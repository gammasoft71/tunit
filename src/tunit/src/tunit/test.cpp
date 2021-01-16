#include "../../include/tunit/test.h"
#include "../../include/tunit/unit_test.h"
#include <exception>

using namespace tunit;

test* test::current_test_ = nullptr;
const test_class* test::current_test_class_ = nullptr;
const unit_test* test::current_unit_test_ = nullptr;
bool __tunit_unit_tests_mode__ = false;

void test::run(const unit_test& unit_test, const tunit::test_class& test_class) {
  current_test_ = this;
  current_test_class_ = &test_class;
  current_unit_test_ = &unit_test;
  
  if (this->ignored() && settings::default_settings().also_run_ignored_tests()) this->status_ = test_status::not_started;

  if ((__tunit_unit_tests_mode__ || settings::default_settings().repeaat_test() != 1) && (this->aborted() || this->failed() || this->succeed())) this->status_ = test_status::not_started;

  if (settings::default_settings().is_match_test_name(test_class.name(), this->name())) {
    if (this->ignored()) {
      try {
        assert::ignore();
      } catch(const tunit::ignore_error&) {
        unit_test.event_listener_->on_test_ignored(tunit::test_event_args(*this, test_class, unit_test));
      }
    } else if (this->not_started()) {
      unit_test.event_listener_->on_test_initialize_start(tunit::test_event_args(*this, test_class, unit_test));
      if (test_class.test_initialize().method() != nullptr)
        test_class.test_initialize().method()();
      unit_test.event_listener_->on_test_initialize_end(tunit::test_event_args(*this, test_class, unit_test));
      
      unit_test.event_listener_->on_test_start(tunit::test_event_args(*this, test_class, unit_test));
      try {
        this->start_time_point = std::chrono::high_resolution_clock::now();
        this->method()();
        this->end_time_point = std::chrono::high_resolution_clock::now();
        if (this->not_started()) this->status_ = test_status::succeed;
        if (this->succeed())
          unit_test.event_listener_->on_test_succeed(tunit::test_event_args(*this, test_class, unit_test));
        /*
        else {
          tunit::settings::default_settings().exit_status(EXIT_FAILURE);
          unit_test.event_listener_->on_test_failed(tunit::test_event_args(*this, test_class, unit_test));
        }
         */
      } catch(const tunit::abort_error&) {
        unit_test.event_listener_->on_test_aborted(tunit::test_event_args(*this, test_class, unit_test));
      } catch(const tunit::assert_error&) {
        tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        unit_test.event_listener_->on_test_failed(tunit::test_event_args(*this, test_class, unit_test));
      } catch(const tunit::ignore_error&) {
        unit_test.event_listener_->on_test_ignored(tunit::test_event_args(*this, test_class, unit_test));
      } catch(const std::exception& e) {
        tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        tunit::test::current_test().message_ = "Exception <" + __tunit_demangle(typeid(e).name()) + "> throws";
        tunit::test::current_test().status_ = test::test_status::failed;
        unit_test.event_listener_->on_test_failed(tunit::test_event_args(*this, test_class, unit_test));
      } catch(...) {
        tunit::settings::default_settings().exit_status(EXIT_FAILURE);
        tunit::test::current_test().message_ = "Exception <excption> throws";
        tunit::test::current_test().status_ = test::test_status::failed;
        unit_test.event_listener_->on_test_failed(tunit::test_event_args(*this, test_class, unit_test));
      }
      
      unit_test.event_listener_->on_test_cleanup_start(tunit::test_event_args(*this, test_class, unit_test));
      if (test_class.test_cleanup().method() != nullptr)
        test_class.test_cleanup().method()();
      unit_test.event_listener_->on_test_cleanup_end(tunit::test_event_args(*this, test_class, unit_test));
      
      unit_test.event_listener_->on_test_end(tunit::test_event_args(*this, test_class, unit_test));
    }
  }
}


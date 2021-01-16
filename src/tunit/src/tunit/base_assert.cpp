#include "../../include/tunit/base_assert.h"
#include "../../include/tunit/settings.h"
#include "../../include/tunit/unit_test.h"
#include "../../include/tunit/test.h"
#include <string>

using namespace tunit;
using namespace std;
using namespace std::string_literals;

void base_assert::abort(const std::string& message, const tunit::line_info& line_info) {
  if (line_info != tunit::line_info::empty())
    tunit::test::current_test().info_ = line_info;
  if (tunit::test::current_test().message_.empty())
    tunit::test::current_test().message_ = !message.empty() ? message : "Test aborted"s;
  tunit::test::current_test().status_ = test::test_status::aborted;
  throw abort_error(tunit::test::current_test().message_);
}

void base_assert::error() {
  tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  tunit::test::current_unit_test().event_listener_->on_test_failed(tunit::test_event_args(tunit::test::current_test(), tunit::test::current_test_class(), tunit::test::current_unit_test()));
}

void base_assert::error(const std::string& expected, const std::string& actual, const std::string& message, const tunit::line_info& line_info) {
  if (line_info != tunit::line_info::empty())
    tunit::test::current_test().info_ = line_info;
  tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
  tunit::test::current_test().actual_ = actual;
  tunit::test::current_test().expect_ = expected;
  base_assert::error();
}

void base_assert::fail(const std::string& expected, const std::string& actual, const std::string& message, const tunit::line_info& line_info) {
  if (line_info != tunit::line_info::empty())
    tunit::test::current_test().info_ = line_info;
  tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
  tunit::test::current_test().actual_ = actual;
  tunit::test::current_test().expect_ = expected;
  tunit::test::current_test().status_ = test::test_status::failed;
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}

void base_assert::ignore(const std::string& message, const tunit::line_info& line_info) {
  if (line_info != tunit::line_info::empty())
    tunit::test::current_test().info_ = line_info;
  tunit::test::current_test().message_ = message != ""s ? message : "Test ignored"s;
  tunit::test::current_test().status_ = test::test_status::ignored;
  throw ignore_error(tunit::test::current_test().message_);
}

void base_assert::succeed(const std::string& message, const tunit::line_info& line_info) {
  if (line_info != tunit::line_info::empty())
    tunit::test::current_test().info_ = line_info;
  tunit::test::current_test().message_ = message;
  if (tunit::test::current_test().status_ != test::test_status::failed)
    tunit::test::current_test().status_ = test::test_status::succeed;
}

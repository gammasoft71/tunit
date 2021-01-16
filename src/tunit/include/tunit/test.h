/// @file
/// @brief Contains tunit::test class.
#pragma once

#include "assert.h"
#include "assert_error.h"
#include "line_info.h"
#include <functional>
#include <chrono>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @cond
  class test_class;
  class unit_test;
  class valid;
  /// @endcond
  
  class test final {
    enum class test_status {
      not_started,
      ignored,
      succeed,
      aborted,
      failed
    };

  public:
    test() = default;
    test(const std::string& name, const std::function<void()>& method, const tunit::line_info& caller) noexcept : test(name, method, false, caller) {}
    test(const std::string& name, const std::function<void()>& method, bool ignore, const tunit::line_info& info) noexcept :  info_(info), method_(method), name_(name), status_(ignore ? test_status::ignored : test_status::not_started) {}
    
    bool aborted() const noexcept {return this->status_ == test_status::aborted;}
    
    const std::string& actual() const noexcept {return this->actual_;}
    
    const std::string& expect() const noexcept {return this->expect_;}
    
    bool failed() const noexcept {return this->status_ == test_status::failed;}
    
    bool ignored() const noexcept {return this->status_ == test_status::ignored;}
    
    bool not_started() const noexcept {return this->status_ == test_status::not_started;}
    
    bool succeed() const noexcept {return this->status_ == test_status::succeed;}
    
    const tunit::line_info line_info() const noexcept {return this->info_;}
    
    std::function<void()> method() const noexcept {return this->method_;}
    
    const std::string& message() const noexcept {return this->message_;}
    
    const std::string& name() const noexcept {return this->name_;}
    
    const std::string& user_message() const noexcept {return this->user_message_;}
    
    std::chrono::milliseconds elapsed_time() const noexcept {
      using namespace std::chrono_literals;
      if (this->start_time_point.time_since_epoch() == 0ms && this->end_time_point.time_since_epoch() == 0ms) return 0ms;
      if (this->end_time_point.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->start_time_point);
      return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_time_point - this->start_time_point);
    }

  private:
    friend class tunit::assert;
    friend class tunit::base_assert;
    friend class tunit::test_class;
    friend class tunit::valid;
    static test& current_test() {return *current_test_;}
    static const test_class& current_test_class() {return *current_test_class_;}
    static const unit_test& current_unit_test() {return *current_unit_test_;}

    void run(const tunit::unit_test& unit_test, const tunit::test_class& test_class);
    
    std::chrono::high_resolution_clock::time_point end_time_point;
    static test* current_test_;
    static const test_class* current_test_class_;
    static const unit_test* current_unit_test_;
    std::string actual_;
    std::string expect_;
    tunit::line_info info_;
    std::string message_;
    std::function<void()> method_;
    std::string name_;
    std::chrono::high_resolution_clock::time_point start_time_point;
    test_status status_ = test_status::not_started;
    std::string user_message_;
  };
}

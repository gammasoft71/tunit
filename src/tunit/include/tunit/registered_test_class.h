/// @file
/// @brief Contains tunit::registered_test_class class.
#pragma once
#include "test_class.h"
#include <memory>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  class registered_test_class final {
  public:
    registered_test_class(const std::string& name, std::shared_ptr<tunit::test_class> test_class) noexcept : tc_(test_class) {this->tc_->name_ = name;}
    
  private:
    friend class tunit::unit_test;

    const std::shared_ptr<tunit::test_class>& test() const noexcept {return this->tc_;}

    std::shared_ptr<tunit::test_class> tc_;
  };
}

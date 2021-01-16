/// @file
/// @brief Contains tunit::test_class_attribute class.
#pragma once
#include "unit_test.h"
#include <memory>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  template <typename TestClass>
  class test_class_attribute final {
  public:
    explicit test_class_attribute(const std::string& name) noexcept {tunit::unit_test::add({name, std::make_shared<TestClass>()});}
  };
}

/// @file
/// @brief Contains tunit::test_initialize_attribute class.
#pragma once
#include "test.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  class test_initialize_attribute {
  public:
    template<typename TestClass>
    test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)()) noexcept :  test_initialize_attribute(name, test_class, method, tunit::line_info()) {}
    
    template<typename TestClass>
    test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)(), const tunit::line_info& caller) noexcept {test_class.add_test_initialize({name, method, caller});}
  };
}

#define test_initialize_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_initialize_attribute : public tunit::test_initialize_attribute { \
  public:\
    template<typename test_class> __test_initialize_attribute(test_class& test) : test_initialize_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __test_initialize_attribute {*this}; \
  static void method_name()


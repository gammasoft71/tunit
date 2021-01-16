#include "assert_unit_tests.h"
#include <tunit/tunit>

namespace unit_tests {
  class test_class_(test_assert_are_equal_double_NaN) {
  public:
    void test_method_(test_case_succeed) {
      double d = std::numeric_limits<double>::quiet_NaN();
      tunit::assert::are_equal(std::numeric_limits<double>::quiet_NaN(), d);
    }
  };
}

void test_(test_assert_are_equal_double_NaN, test_output) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_NaN.*");
  std::stringstream ss;
  tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_assert_are_equal_double_NaN.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_are_equal_double_NaN, test_result) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_NaN.*");
  std::stringstream ss;
  assert_value_(0, tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}

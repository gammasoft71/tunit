#include "assert_unit_tests.h"
#include <tunit/tunit>

namespace unit_tests {
  class test_class_(test_string_assert_are_equal_ignoring_case_u32string_failed) {
  public:
    void test_method_(test_case_failed) {
      std::u32string s = U"VALUE";
      tunit::string_assert::are_equal_ignoring_case(U"key", s);
    }
  };
}

void test_(test_string_assert_are_equal_ignoring_case_u32string_failed, test_output) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_string_assert_are_equal_ignoring_case_u32string_failed.*");
  std::stringstream ss;
  tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_string_assert_are_equal_ignoring_case_u32string_failed.test_case_failed\n"
                "    Expected: \"key\", ignoring case\n"
                "    But was:  \"VALUE\"\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_string_assert_are_equal_ignoring_case_u32string_failed, test_result) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_string_assert_are_equal_ignoring_case_u32string_failed.*");
  std::stringstream ss;
  assert_value_(1, tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}

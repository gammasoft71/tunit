#include "assert_unit_tests.h"
#include <tunit/tunit>
#include <string>

namespace unit_tests {
  class test_class_(test_assert_is_empty_string_failed) {
  public:
    void test_method_(test_case_failed) {
      std::string s = "string";
      tunit::assert::is_empty(s);
    }
  };
}

void test_(test_assert_is_empty_string_failed, test_output) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_is_empty_string_failed.*");
  std::stringstream ss;
  tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_assert_is_empty_string_failed.test_case_failed\n"
                "    Expected: collection <empty>\n"
                "    But was:  < 's', 't', 'r', 'i', 'n', 'g' >\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_empty_string_failed, test_result) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_is_empty_string_failed.*");
  std::stringstream ss;
  assert_value_(1, tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}

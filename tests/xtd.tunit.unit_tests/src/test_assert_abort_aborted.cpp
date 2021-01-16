#include "assert_unit_tests.h"
#include <tunit/tunit>

namespace unit_tests {
  class test_class_(test_assert_abort_aborted) {
  public:
    void test_method_(test_case_aborted) {
      tunit::assert::abort(tunit::line_info {"test_assert_abort_aborted.cpp", 8});
    }
  };
}

void test_(test_assert_abort_aborted, test_output) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_abort_aborted.*");
  std::stringstream ss;
  tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  ABORTED test_assert_abort_aborted.test_case_aborted\n"
                "    Test aborted\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_abort_aborted, test_result) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_abort_aborted.*");
  std::stringstream ss;
  assert_value_(0, tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}

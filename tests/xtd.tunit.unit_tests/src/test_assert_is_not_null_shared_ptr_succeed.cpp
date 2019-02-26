#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <memory>

namespace unit_tests {
  class test_class_(test_assert_is_not_null_shared_ptr_succeed) {
  public:
    void test_method_(test_case_succeed) {
      std::shared_ptr<int> p = std::make_shared<int>(42);
      xtd::tunit::assert::is_not_null(p, xtd::tunit::line_info {"test_assert_is_not_null_shared_ptr_succeed.cpp", 10});
    }
  };
}

void test_(test_assert_is_not_null_shared_ptr_succeed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_shared_ptr_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_is_not_null_shared_ptr_succeed\n"
                "    PASSED test_case_succeed\n"
                "  End 1 test from test_assert_is_not_null_shared_ptr_succeed\n"
                "\n"
                "  Summary :\n"
                "    PASSED 1 test.\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_is_not_null_shared_ptr_succeed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_shared_ptr_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
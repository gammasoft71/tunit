/// @file
/// @brief Contains tunit::test_event_args class.
#pragma once
#include "test_class.h"
#include "test.h"
#include "tunit_event_args.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief Provides data for the tunit::test events.
  class test_event_args : public tunit::tunit_event_args {
  public:
    /// @brief Create a new instance of class class_event_args.
    /// @param test Current testt.
    /// @param test_class Current test_class.
    explicit test_event_args(const tunit::test& test, const tunit::test_class& test_class, const tunit::unit_test& unit_test) : tunit::tunit_event_args(unit_test), t_(test), tc_(test_class) {}

    /// @brief Gets current test.
    /// @return Current test.
    const tunit::test& test() const noexcept {return this->t_;}

    /// @brief Gets current class test.
    /// @return Current class test.
    const tunit::test_class& test_class() const noexcept {return this->tc_;}

  private:
    const tunit::test& t_;
    const tunit::test_class& tc_;
  };
}

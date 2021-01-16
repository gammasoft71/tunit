/// @file
/// @brief Contains tunit::class_event_args class.
#pragma once
#include "test_class.h"
#include "tunit_event_args.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief Provides data for the tunit::class_test events.
  class class_event_args : public tunit::tunit_event_args {
  public:
    /// @brief Create a new instance of class class_event_args.
    /// @param test_class Current class_test.
    class_event_args(const tunit::test_class& test_class, const tunit::unit_test& unit_test) : tunit::tunit_event_args(unit_test), tc_(test_class) {}

    /// @brief Gets current class test.
    /// @return Current class test.
    const tunit::test_class& test_class() const noexcept {return this->tc_;}

  private:
    const tunit::test_class& tc_;
  };
}

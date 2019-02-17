/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "test_class.hpp"
#include "tunit_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @brief Provides data for the xtd::tunit::class_test events.
    class class_event_args : public xtd::tunit::tunit_event_args {
    public:
      /// @brief Create a new instance of class class_event_args.
      /// @param test_class Current class_test.
     explicit class_event_args(const xtd::tunit::test_class& test_class) : tc_(test_class) {}

      /// @brief Gets current class test.
      /// @return Current class test.
      const xtd::tunit::test_class& test_class() const noexcept {return this->tc_;}

    private:
      const xtd::tunit::test_class& tc_;
    };
  }
}

/// @file
/// @brief Contains tunit::test_state enum class.
#pragma once
#include "test.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief Represent the test state enumeration used bu test.
  enum class test_state {
    /// @brief Test is considered.
    considered,
    /// @brief Test is ignored.
    ignored
  };
}

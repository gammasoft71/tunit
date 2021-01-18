# tunit

**Modern c++17 unit testing framework on Windows, macOS, Linux, iOS and android.**

[![tunit](docs/pictures/tunit_header.png)](https://gammasoft71.wixsite.com/tunit)

## Continuous Integration build status

| Operating system | Status                                                                                                                                      |
|------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| Windows          | [![Build status](https://ci.appveyor.com/api/projects/status/1h8y1d4lodnk1wbb?svg=true)](https://ci.appveyor.com/project/gammasoft71/tunit) |
| macOS            | [![Build Status](https://travis-ci.org/gammasoft71/tunit.svg?branch=master)](https://travis-ci.org/gammasoft71/tunit)                       |
| Linux            | [![Build Status](https://travis-ci.org/gammasoft71/tunit.svg?branch=master)](https://travis-ci.org/gammasoft71/tunit)                       |

## Download the latest stable tunit version

[![SourceForge Download tunit](https://img.shields.io/sourceforge/dt/tunitpro.svg)](https://sourceforge.net/projects/tunitpro/files/latest/download)

## Features

* An [xUnit](https://en.wikipedia.org/wiki/XUnit) test framework.
* Auto registration of class and method based tests.
* Rich set of assertions.
* ...

For more information see:
* [website](https://gammasoft71.wixsite.com/tunit) 
* [markdown documentations](docs/home.md)
* [sources](https://github.com/gammasoft71/tunit)
* [Reference Guide](https://codedocs.xyz/gammasoft71/tunit/)

## Examples

The classic first application 'Hello World'.

### src/tunit_hello_world.cpp

```c++
#include <tunit/tunit>
#include <string>

using namespace std;
using namespace tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

// The main entry point for the application.
int main() {
  return console_unit_test().run();
}
```

### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.3)

project(tunit_hello_world)
find_package(tunit REQUIRED)
add_executable(${PROJECT_NAME} src/tunit_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} tunit)
```

### Output
```
tart 2 tests from 1 test case
Run tests:
  SUCCEED hello_world_test.create_string_from_literal (0 ms total)
  SUCCEED hello_world_test.create_string_from_chars (0 ms total)

Test results:
  SUCCEED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

## Getting Started

* [Installation](docs/downloads.md) provides download and install documentation.
* [Portability](docs/portability.md) provides information about C++, libraries dependency, Operating System suported, Compilators and Devepment Environment tools.
* [Examples](docs/examples.md) provides some examples.

______________________________________________________________________________________________

© 2021 Gammasoft.

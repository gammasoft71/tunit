cmake_minimum_required(VERSION 3.3)

# Project
project(tunit VERSION 1.0.0)
set(INCLUDES
  include/tunit/__console_color.h
  include/tunit/__demangle.h
  include/tunit/__tunit_join__items.h
  include/tunit/abort_error.h
  include/tunit/assert.h
  include/tunit/assert_error.h
  include/tunit/assume.h
  include/tunit/base_assert.h
  include/tunit/class_cleanup_attribute.h
  include/tunit/class_event_args.h
  include/tunit/class_initialize_attribute.h
  include/tunit/collection_assert.h
  include/tunit/collection_assume.h
  include/tunit/collection_valid.h
  include/tunit/console_unit_test.h
  include/tunit/default_insert_basic_ostream_operator.h
  include/tunit/default_main.h
  include/tunit/directory_assert.h
  include/tunit/directory_assume.h
  include/tunit/directory_valid.h
  include/tunit/event_listener.h
  include/tunit/file_assert.h
  include/tunit/file_assume.h
  include/tunit/file_valid.h
  include/tunit/ignore_error.h
  include/tunit/line_info.h
  include/tunit/main_page.h
  include/tunit/ostream_event_listener.h
  include/tunit/ostream_unit_test.h
  include/tunit/settings.h
  include/tunit/string_assert.h
  include/tunit/string_assume.h
  include/tunit/string_valid.h
  include/tunit/test.h
  include/tunit/registered_test_class.h
  include/tunit/test_cleanup_attribute.h
  include/tunit/test_event_args.h
  include/tunit/test_initialize_attribute.h
  include/tunit/test_method_attribute.h
  include/tunit/test_class.h
  include/tunit/test_class_attribute.h
  include/tunit/test_state.h
  include/tunit/tunit
  include/tunit/tunit.h
  include/tunit/tunit_event_args.h
  include/tunit/tunit_main.h
  include/tunit/unit_test.h
  include/tunit/valid.h
  include/tunit/xtd.tunit
  include/tunit/xtd.tunit.h
)
set(SOURCES
  src/tunit/__console_color_gcc.cpp
  src/tunit/__console_color_win32.cpp
  src/tunit/__demangle_gcc.cpp
  src/tunit/__demangle_win32.cpp
  src/tunit/base_assert.cpp
  src/tunit/tunit_main.cpp
  src/tunit/test.cpp
  src/tunit/test_class.cpp
  src/tunit/unit_test.cpp
)
source_group(include\\tunit FILES ${INCLUDES})
source_group(src\\tunit FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/tunit/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)

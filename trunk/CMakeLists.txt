cmake_minimum_required (VERSION 2.8)

project (RELVIEW)

enable_testing()

add_subdirectory (rel_view ${CMAKE_CURRENT_BINARY_DIR}/rel_view)
add_subdirectory (unit_tests ${CMAKE_CURRENT_BINARY_DIR}/unit_tests)


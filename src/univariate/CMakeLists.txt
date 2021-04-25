add_library(
  univariate_function
  univariate_function.cc
  univariate_container.cc
)

set_property(TARGET univariate_function PROPERTY CXX_STANDARD 20)

target_include_directories(univariate_function PUBLIC "${CMAKE_SOURCE_DIR}/src")

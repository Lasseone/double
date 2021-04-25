cmake_minimum_required(VERSION 3.12)
project(double)

add_subdirectory(src)

add_executable(run src/run.cc)

target_include_directories(run PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(
  run 
  operation
  univariate_function
)

set_property(TARGET run PROPERTY CXX_STANDARD 20)

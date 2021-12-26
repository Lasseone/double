cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCMAKE_BUILD_TYPE=Release" CACHE STRING "Default CXX options" FORCE)

project(auto_diff)

set(INSTALL_BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(TOP_LEVEL ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")

add_subdirectory(src)
add_subdirectory(benchmarking)
add_executable(run src/run.cc)

target_include_directories(run PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(
  run 
  operation
  univariate_function
)

set_property(TARGET run PROPERTY CXX_STANDARD 20)
install(TARGETS run DESTINATION ${INSTALL_BIN_DIR})

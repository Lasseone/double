project(auto_diff)

include_directories(lib/benchmark/include) # ../tests/lib/googletest/googletest/include)

set(SOURCE_FILES benchmarking.cpp)

add_executable(benchmarking ${SOURCE_FILES})

target_include_directories(benchmarking PUBLIC "${TOP_LEVEL}/src")

target_link_libraries(benchmarking
        benchmark::benchmark 
        -lpthread
        operation
        univariate_function
)
if (NOT CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DNDEBUG)
endif()
set_property(TARGET benchmarking PROPERTY CXX_STANDARD 20)
install(TARGETS benchmarking DESTINATION ${INSTALL_BIN_DIR})

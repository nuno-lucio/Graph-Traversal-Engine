cmake_minimum_required(VERSION 3.14)

project(Graph-Traversal-Engine VERSION 2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(ENGINE_SOURCES
    src/Graph.cpp
    src/GraphFactory.cpp
    src/GraphFileFactory.cpp
    src/GraphStdinFactory.cpp
    src/DFS.cpp
    src/BFS.cpp
    src/Display.cpp)

add_library(GraphEngineLib ${ENGINE_SOURCES})

add_executable(GraphEngine src/main.cpp)

target_link_libraries(GraphEngine PRIVATE GraphEngineLib)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES "tests/test_*.cpp")

add_executable(GraphEngineTests ${TEST_SOURCES})

target_link_libraries(GraphEngineTests PRIVATE GraphEngineLib gtest_main)

include(GoogleTest)
gtest_discover_tests(GraphEngineTests)

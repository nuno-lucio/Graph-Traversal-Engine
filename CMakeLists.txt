cmake_minimum_required(VERSION 3.10)

project(Graph-Traversal-Engine VERSION 2.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/Graph.cpp
    src/GraphFactory.cpp
    src/GraphFileFactory.cpp
    src/GraphStdinFactory.cpp
    src/DFS.cpp
    src/BFS.cpp
    src/Display.cpp)

add_executable(GraphEngine ${SOURCES})

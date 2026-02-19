# Graph Traversal Engine in C++

This engine was designed with a modular **Object-Oriented architecture**.

This project implements **iterative DFS and BFS** (Depth-First-Search and Breadth-First-Search).

---

## Features
- Iterative DFS using a stack
  - **Discovery**, **Finishing times** and **Parents** for each vertex
- Iterative BFS
  - **Distance** and **Parents** for vertices in the path
- Reads graph from standard input or file
- Prints results to standard output or file

---

## Input Format
The program reads a 0 indexed graph in **adjacency list format**:
```
numberOfVertices numberOfVerticesWithAdjacencies isDirectedGraph(1/0)

vertexID Degree neighbor1 neighbor2 ...

...
```

### Example
```
8 6 1
0 1 2
1 2 2 5
2 2 0 6
4 2 6 7
5 1 6
6 2 2 5
```
![Example Graph](https://github.com/nuno-lucio/Graph-Traversal-Engine/raw/master/examples/example_graph.png)

---

## Build Instructions

### Option A: Using CMake (Recommended)
This project uses CMake for cross-platform build configuration.

1.  Create a build directory:
    ```bash
    mkdir build && cd build
    ```
2.  Generate the Makefile:
    ```bash
    cmake ..
    ```
3.  Compile:
    ```bash
    make
    ```

### Option B: Using g++ Directly
```bash
g++ -std=c++14 -O3 -Wall -Iinclude src/*.cpp -o GraphEngine
```

---

## Running the Engine

**Usage:**
```bash
./GraphEngine <algorithm_flag> <start_vertex> [optional_filename]
```

***Flags***:

-   d: Depth-First-Search (DFS)
-   b: Breadth-First-Search (BFS)

***Examples***:
1. Run DFS starting at vertex 0 from file 
```bash
./GraphEngine d 0 examples/example_graph.txt
```
2. Run BFS starting at vertex 2 from standard input
```bash
./GraphEngine b 2 < examples/example_graph.txt
```

## Docker Support
This project includes a multi-stage Dockerfile for containerized execution.

1.  Build the Image:
    ```bash
    docker build -t graph-engine .
    ```
2.  Run with Docker:
    (must use **-i** flag to pipe files into container)
    ```bash
    docker run -i graph-engine d 0 < examples/example_graph.txt
    ```

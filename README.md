# Graph Traversal Engine in C++

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

## Build
```
g++ -std=c++14 -O3 -Wall -Iinclude src/*.cpp -o GraphEngine
```

---

## Run
***Option***:

-'d' -> DFS

-'b' -> BFS

```
./GraphEngine <option> <starting vertex> *<filename>
./GraphEngine d 0 examples/example_graph.txt
./GraphEngine b 2 < examples/example_graph.txt
```

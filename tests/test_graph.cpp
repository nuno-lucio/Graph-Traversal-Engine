/**********
 * Test Graph
 * Author: Nuno Lucio
 **********/

#include <gtest/gtest.h>
#include "Graph.hpp"
#include <algorithm>
#include <vector>

TEST(GraphTest, InitializationDirectedGraph)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = true;
    Graph g(isDirected, nVertices);

    // Action
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);

    // Check
    EXPECT_TRUE(g.isDirectedGraph());
    EXPECT_EQ(g.getNumberOfVertices(), nVertices);
    EXPECT_EQ(g.getNumberOfEdges(), 3);
}

TEST(GraphTest, InitializationUndirectedGraph)
{
    // Setup
    const Vertex nVertices = 8;
    const bool isDirected = false;
    Graph g(isDirected, nVertices);

    // Action
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 6);
    g.addEdge(3, 6);
    g.addEdge(4, 5);

    // Check
    EXPECT_FALSE(g.isDirectedGraph());
    EXPECT_EQ(g.getNumberOfVertices(), nVertices);
    EXPECT_EQ(g.getNumberOfEdges(), 6);
}

TEST(GraphTest, InitializationNoEdges)
{
    // Setup
    const Vertex nVertices = 6;
    const bool isDirected = false;
    Graph g(isDirected, nVertices);

    // Check
    EXPECT_FALSE(g.isDirectedGraph());
    EXPECT_EQ(g.getNumberOfVertices(), nVertices);
    EXPECT_EQ(g.getNumberOfEdges(), 0);
}

TEST(GraphTest, InitializationWithEdges)
{
    // Setup
    const Vertex nVertices = 3;
    const bool isDirected = true;
    const std::vector<std::vector<Vertex>> adjacencyList{{1, 2}, {2}, {}};
    Graph g(isDirected, nVertices, adjacencyList);

    // Check
    const auto &neighbors0 = g.getNeighbors(0);
    const auto &neighbors1 = g.getNeighbors(1);
    const auto &neighbors2 = g.getNeighbors(2);
    EXPECT_TRUE(g.isDirectedGraph());
    EXPECT_EQ(neighbors0, adjacencyList[0]);
    EXPECT_EQ(neighbors1, adjacencyList[1]);
    EXPECT_EQ(neighbors2, adjacencyList[2]);
}

TEST(GraphTest, AddEdgesUndirected)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = false;
    Graph g(isDirected, nVertices);

    // Action
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Check (False -> Found)
    const auto &neighbors0 = g.getNeighbors(0);
    const auto &neighbors1 = g.getNeighbors(1);
    const auto &neighbors2 = g.getNeighbors(2);
    EXPECT_EQ(g.getNumberOfEdges(), 3);
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 1) == neighbors0.end());
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 2) == neighbors0.end());
    EXPECT_FALSE(std::find(neighbors1.begin(), neighbors1.end(), 0) == neighbors1.end());
    EXPECT_FALSE(std::find(neighbors1.begin(), neighbors1.end(), 2) == neighbors1.end());
    EXPECT_FALSE(std::find(neighbors2.begin(), neighbors2.end(), 0) == neighbors2.end());
    EXPECT_FALSE(std::find(neighbors2.begin(), neighbors2.end(), 1) == neighbors2.end());
}

TEST(GraphTest, AddEdgesDirected)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = true;
    Graph g(isDirected, nVertices);

    // Action
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Check (False -> Found)
    const auto &neighbors0 = g.getNeighbors(0);
    const auto &neighbors1 = g.getNeighbors(1);
    const auto &neighbors2 = g.getNeighbors(2);
    EXPECT_EQ(g.getNumberOfEdges(), 3);
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 1) == neighbors0.end());
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 2) == neighbors0.end());
    EXPECT_TRUE(std::find(neighbors1.begin(), neighbors1.end(), 0) == neighbors1.end());
    EXPECT_FALSE(std::find(neighbors1.begin(), neighbors1.end(), 2) == neighbors1.end());
    EXPECT_TRUE(std::find(neighbors2.begin(), neighbors2.end(), 0) == neighbors2.end());
    EXPECT_TRUE(std::find(neighbors2.begin(), neighbors2.end(), 1) == neighbors2.end());
}

TEST(GraphTest, RemoveEdgesUndirected)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = false;
    Graph g(isDirected, nVertices);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Action
    g.removeEdge(0, 2);

    // Check
    EXPECT_EQ(g.getNumberOfEdges(), 2);
    const auto &neighbors0 = g.getNeighbors(0);
    const auto &neighbors2 = g.getNeighbors(2);
    EXPECT_TRUE(std::find(neighbors0.begin(), neighbors0.end(), 2) == neighbors0.end());
    EXPECT_TRUE(std::find(neighbors2.begin(), neighbors2.end(), 0) == neighbors2.end());
}

TEST(GraphTest, RemoveEdgesDirected)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = true;
    Graph g(isDirected, nVertices);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Action
    g.removeEdge(0, 2);

    // Check
    EXPECT_EQ(g.getNumberOfEdges(), 2);
    const auto &neighbors0 = g.getNeighbors(0);
    EXPECT_TRUE(std::find(neighbors0.begin(), neighbors0.end(), 2) == neighbors0.end());
}

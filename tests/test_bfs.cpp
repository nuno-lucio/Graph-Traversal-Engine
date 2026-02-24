/**********
 * Test BFS
 * Author: Nuno Lucio
 **********/

#include <gtest/gtest.h>
#include "Graph.hpp"
#include "BFS.hpp"
#include <stdexcept>

TEST(BfsTest, RegularBFS)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = false;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    BFS bfs;

    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Action
    bfs.execute(g, startVertex);

    // Check Distances
    const auto &distances = bfs.getDistances();
    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 2);
    EXPECT_EQ(distances[3], NO_DISTANCE);

    // Check Parents
    const auto &parents = bfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 1);
    EXPECT_EQ(parents[3], NO_PARENT);
}

TEST(BfsTest, CycleGraph)
{
    // Setup
    const Vertex nVertices = 3;
    const bool isDirected = false;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    BFS bfs;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    // Action
    bfs.execute(g, startVertex);

    // Check Distances
    const auto &distances = bfs.getDistances();
    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 1);

    // Check Parents
    const auto &parents = bfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 0);
}

TEST(BfsTest, SingleVertex)
{
    // Setup
    const Vertex nVertices = 1;
    const bool isDirected = false;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    BFS bfs;

    // Action
    bfs.execute(g, startVertex);

    // Check Distances
    const auto &distances = bfs.getDistances();
    EXPECT_EQ(distances[0], 0);

    // Check Parents
    const auto &parents = bfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
}

TEST(BfsTest, StarGraph)
{
    // Setup
    const Vertex nVertices = 5;
    const bool isDirected = false;
    const Vertex startVertex = 3;
    Graph g(isDirected, nVertices);
    BFS bfs;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    // Action
    bfs.execute(g, startVertex);

    // Check Distances
    const auto &discoveryTimes = bfs.getDistances();
    EXPECT_EQ(discoveryTimes[0], 1);
    EXPECT_EQ(discoveryTimes[1], 2);
    EXPECT_EQ(discoveryTimes[2], 2);
    EXPECT_EQ(discoveryTimes[3], 0);
    EXPECT_EQ(discoveryTimes[4], 1);

    // Check Parents
    const auto &parents = bfs.getParents();
    EXPECT_EQ(parents[0], 3);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 0);
    EXPECT_EQ(parents[3], NO_PARENT);
    EXPECT_EQ(parents[4], 3);
}

TEST(BfsTest, InvalidStartVertex)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = false;
    const Vertex startVertex = 99;
    Graph g(isDirected, nVertices);
    BFS bfs;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Action and Check
    EXPECT_THROW(bfs.execute(g, startVertex), std::out_of_range);
}

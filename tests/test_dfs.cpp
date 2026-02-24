/**********
 * Test DFS
 * Author: Nuno Lucio
 **********/

#include <gtest/gtest.h>
#include "Graph.hpp"
#include "DFS.hpp"
#include <stdexcept>

TEST(DfsTest, RegularDFS)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = true;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    DFS dfs;

    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Action
    dfs.execute(g, startVertex);

    // Check Discovery Times
    const auto &discoveryTimes = dfs.getDiscoveryTimes();
    EXPECT_EQ(discoveryTimes[0], 1);
    EXPECT_EQ(discoveryTimes[1], 2);
    EXPECT_EQ(discoveryTimes[2], 3);
    EXPECT_EQ(discoveryTimes[3], 7);

    // Check Final Times
    const auto &finalTimes = dfs.getFinalTimes();
    EXPECT_EQ(finalTimes[0], 6);
    EXPECT_EQ(finalTimes[1], 5);
    EXPECT_EQ(finalTimes[2], 4);
    EXPECT_EQ(finalTimes[3], 8);

    // Check Parents
    const auto &parents = dfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 1);
    EXPECT_EQ(parents[3], NO_PARENT);
}

TEST(DfsTest, CycleGraph)
{
    // Setup
    const Vertex nVertices = 3;
    const bool isDirected = true;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    DFS dfs;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    // Action
    dfs.execute(g, startVertex);

    // Check Discovery Times
    const auto &discoveryTimes = dfs.getDiscoveryTimes();
    EXPECT_EQ(discoveryTimes[0], 1);
    EXPECT_EQ(discoveryTimes[1], 2);
    EXPECT_EQ(discoveryTimes[2], 3);

    // Check Final Times
    const auto &finalTimes = dfs.getFinalTimes();
    EXPECT_EQ(finalTimes[0], 6);
    EXPECT_EQ(finalTimes[1], 5);
    EXPECT_EQ(finalTimes[2], 4);

    // Check Parents
    const auto &parents = dfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 1);
}

TEST(DfsTest, SingleVertex)
{
    // Setup
    const Vertex nVertices = 1;
    const bool isDirected = true;
    const Vertex startVertex = 0;
    Graph g(isDirected, nVertices);
    DFS dfs;

    // Action
    dfs.execute(g, startVertex);

    // Check Discovery Times
    const auto &discoveryTimes = dfs.getDiscoveryTimes();
    EXPECT_EQ(discoveryTimes[0], 1);

    // Check Final Times
    const auto &finalTimes = dfs.getFinalTimes();
    EXPECT_EQ(finalTimes[0], 2);

    // Check Parents
    const auto &parents = dfs.getParents();
    EXPECT_EQ(parents[0], NO_PARENT);
}

TEST(DfsTest, StarGraph)
{
    // Setup
    const Vertex nVertices = 5;
    const bool isDirected = false;
    const Vertex startVertex = 3;
    Graph g(isDirected, nVertices);
    DFS dfs;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    // Action
    dfs.execute(g, startVertex);

    // Check Discovery Times
    const auto &discoveryTimes = dfs.getDiscoveryTimes();
    EXPECT_EQ(discoveryTimes[0], 2);
    EXPECT_EQ(discoveryTimes[1], 3);
    EXPECT_EQ(discoveryTimes[2], 5);
    EXPECT_EQ(discoveryTimes[3], 1);
    EXPECT_EQ(discoveryTimes[4], 7);

    // Check Final Times
    const auto &finalTimes = dfs.getFinalTimes();
    EXPECT_EQ(finalTimes[0], 9);
    EXPECT_EQ(finalTimes[1], 4);
    EXPECT_EQ(finalTimes[2], 6);
    EXPECT_EQ(finalTimes[3], 10);
    EXPECT_EQ(finalTimes[4], 8);

    // Check Parents
    const auto &parents = dfs.getParents();
    EXPECT_EQ(parents[0], 3);
    EXPECT_EQ(parents[1], 0);
    EXPECT_EQ(parents[2], 0);
    EXPECT_EQ(parents[3], NO_PARENT);
    EXPECT_EQ(parents[4], 0);
}

TEST(DfsTest, InvalidStartVertex)
{
    // Setup
    const Vertex nVertices = 4;
    const bool isDirected = false;
    const Vertex startVertex = 99;
    Graph g(isDirected, nVertices);
    DFS dfs;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Action and Check
    EXPECT_THROW(dfs.execute(g, startVertex), std::out_of_range);
}

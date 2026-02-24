/**********
 * Test GraphFactory
 * Author: Nuno Lucio
 **********/

#include <gtest/gtest.h>
#include "GraphFactory.hpp"
#include "Graph.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>

// Mock class
class StringTestFactory : public GraphFactory
{
    private:
    std::istringstream stringStream;
    public:
    StringTestFactory(const std::string &str) : stringStream(str) {}
    Graph createGraph() override { return read(stringStream); }
};

TEST(GraphFactoryTest, ReadValidGraph)
{
    // Setup
    const std::string testInput = "4 3 1\n0 2 1 2\n1 1 2\n2 1 1";
    StringTestFactory factory(testInput);

    // Action
    Graph g = factory.createGraph();

    // Check
    EXPECT_TRUE(g.isDirectedGraph());
    EXPECT_EQ(g.getNumberOfVertices(), 4);
    EXPECT_EQ(g.getNumberOfEdges(), 4);
    const auto &neighbors0 = g.getNeighbors(0);
    const auto &neighbors1 = g.getNeighbors(1);
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 1) == neighbors0.end());
    EXPECT_FALSE(std::find(neighbors0.begin(), neighbors0.end(), 2) == neighbors0.end());
    EXPECT_FALSE(std::find(neighbors1.begin(), neighbors1.end(), 2) == neighbors1.end());
}

TEST(GraphFactoryTest, ReadDisconnectedGraph)
{
    // Setup
    const std::string testInput = "1 0 0\n";
    StringTestFactory factory(testInput);

    // Action
    Graph g = factory.createGraph();

    // Check
    EXPECT_FALSE(g.isDirectedGraph());
    EXPECT_EQ(g.getNumberOfVertices(), 1);
    EXPECT_EQ(g.getNumberOfEdges(), 0);
}

TEST(GraphFactoryTest, ReadInvalidGraph_InvalidHeader)
{
    // Setup
    const std::string testInput = "4 hello world\n0 2 1 2\n1 1 2\n2 1 3\n";
    StringTestFactory factory(testInput);

    // Action and Check
    EXPECT_THROW(factory.createGraph(), std::runtime_error);
}

TEST(GraphFactoryTest, ReadInvalidGraph_MissingAdjacencies)
{
    // Setup
    const std::string testInput = "4 3 1\n0 2 1 2\n1 1 2\n";
    StringTestFactory factory(testInput);

    // Action and Check
    EXPECT_THROW(factory.createGraph(), std::runtime_error);
}

TEST(GraphFactoryTest, ReadInvalidGraph_MissingAdjacencies_2)
{
    // Setup
    const std::string testInput = "4 3 1\n0 2 1 2\n1 1 2\n2 1\n";
    StringTestFactory factory(testInput);

    // Action and Check
    EXPECT_THROW(factory.createGraph(), std::runtime_error);
}

TEST(GraphFactoryTest, ReadInvalidGraph_OutOfBoundsNeighbor)
{
    // Setup
    const std::string testInput = "4 3 1\n0 2 1 2\n1 1 2\n2 1 99\n";
    StringTestFactory factory(testInput);

    // Action and Check
    EXPECT_THROW(factory.createGraph(), std::out_of_range);
}

TEST(GraphFactoryTest, ReadInvalidGraph_OutOfBoundsVertex)
{
    // Setup
    const std::string testInput = "4 3 1\n0 2 1 2\n-1 1 2\n2 1 3\n";
    StringTestFactory factory(testInput);

    // Action and Check
    EXPECT_THROW(factory.createGraph(), std::out_of_range);
}

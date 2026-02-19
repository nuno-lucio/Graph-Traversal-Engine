/**********
 * Graph Traversal Engine
 * Author: Nuno Lucio
 **********/

#include "../include/Graph.hpp"
#include "../include/GraphFactory.hpp"
#include "../include/GraphStdinFactory.hpp"
#include "../include/GraphFileFactory.hpp"
#include "../include/GraphAlgorithm.hpp"
#include "../include/DFS.hpp"
#include "../include/BFS.hpp"
#include "../include/Display.hpp"
#include <memory>
#include <iostream>

enum options {dfs='d', bfs='b'};

int run(const char opt, const unsigned int startVertex, const std::string &filename)
{
    // Create graph factory
    std::unique_ptr<GraphFactory> factory;

    if(!filename.empty())
    {
        factory = std::make_unique<GraphFileFactory>(filename);
    }
    else
    {
        factory = std::make_unique<GraphStdinFactory>();
    }

    // Produce graph
    Graph graph = factory->createGraph();

    if(graph.getNumberOfVertices() <= startVertex)
    {
        std::cout << "The selected starting vertex does not exist in the graph!" << std::endl;
        return EXIT_FAILURE;
    }

    std::unique_ptr<GraphAlgorithm> algorithm;

    // Select the chosen algorithm
    if(opt == options::dfs)
    {
        algorithm = std::make_unique<DFS>();
    }
    else if(opt == options::bfs)
    {
        algorithm = std::make_unique<BFS>();
    }

    // Run algorithm and display results
    algorithm->execute(graph, startVertex);
    Display display;
    algorithm->print(display, std::cout);

    return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
    // Check valid number of arguments
    if(argc < 3 || argc > 4)
    {
        std::cout << "Wrong number of arguments! Usage: <option: d, b> <start vertex> <graph>" << std::endl;
        return EXIT_FAILURE;
    }

    // Check for graph filename input
    std::string filename;
    if(argc == 4)
    {
        filename = argv[3];
    }

    // Decide algorithm to run
    switch(argv[1][0])
    {
    case options::dfs: return run(options::dfs, std::stoul(argv[2]), filename);
    case options::bfs: return run(options::bfs, std::stoul(argv[2]), filename);
    default: std::cout << "Invalid option! Usage: <option: d, b> <start vertex> <graph>" << std::endl;
        return EXIT_FAILURE;
    }
}

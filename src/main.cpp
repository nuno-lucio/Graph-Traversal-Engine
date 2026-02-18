/**********
 * Graph Traversal Engine
 * Author: Nuno Lucio
 **********/

#include "../include/Graph.hpp"
#include "../include/GraphFactory.hpp"
#include "../include/GraphStdinFactory.hpp"
#include "../include/GraphAlgorithm.hpp"
#include "../include/DFS.hpp"
#include "../include/Display.hpp"
#include <memory>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::unique_ptr<GraphFactory> factory = std::make_unique<GraphStdinFactory>();
    Graph graph = factory->createGraph();

    std::unique_ptr<GraphAlgorithm> algorithm = std::make_unique<DFS>();
    algorithm->execute(graph, 0);
    Display display;
    algorithm->print(display, std::cout);

    return 0;
}

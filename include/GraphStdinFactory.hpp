/**********
 * Produces Graphs from standard input
 * Author: Nuno Lucio
 **********/

#ifndef GRAPH_STDIN_FACTORY_HPP
#define GRAPH_STDIN_FACTORY_HPP

#include "GraphFactory.hpp"

class GraphStdinFactory : public GraphFactory
{
    public:
    Graph createGraph() override;
};

#endif // GRAPH_STDIN_FACTORY_HPP

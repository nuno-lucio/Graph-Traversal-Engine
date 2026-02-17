/**********
 * Produces Graphs
 * Author: Nuno Lucio
 **********/

#ifndef GRAPH_FACTORY_HPP
#define GRAPH_FACTORY_HPP

#include "Graph.hpp"
#include <istream>

class GraphFactory
{
    public:
    virtual ~GraphFactory() = default;
    virtual Graph createGraph() = 0;

    protected:
    Graph read(std::istream &in);
};

#endif // GRAPH_FACTORY_HPP

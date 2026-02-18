/**********
 * GraphAlgorithm representation
 * Author: Nuno Lucio
 **********/

#ifndef GRAPH_ALGORITHM_HPP
#define GRAPH_ALGORITHM_HPP

#include "Graph.hpp"
#include <vector>
#include <limits>
#include <ostream>

constexpr unsigned int NO_PARENT = std::numeric_limits<Vertex>::max();

class Display;

class GraphAlgorithm
{
    protected:
    std::vector<Vertex> parents;

    public:
    virtual ~GraphAlgorithm() = default;
    virtual void execute(const Graph &graph, Vertex startVertex) = 0;
    const std::vector<Vertex>& getParents() const { return parents; }
    virtual void print(const Display &display, std::ostream &out) const = 0;
};

#endif // GRAPH_ALGORITHM_HPP

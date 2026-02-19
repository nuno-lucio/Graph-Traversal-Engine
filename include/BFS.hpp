/**********
 * Traverses Graph with Iterative Breadth-First-Search Algorithm
 * Author: Nuno Lucio
 **********/

#ifndef BFS_HPP
#define BFS_HPP

#include "GraphAlgorithm.hpp"
#include <vector>

constexpr unsigned int NO_DISTANCE = std::numeric_limits<Vertex>::max();

class BFS : public GraphAlgorithm
{
    private:
    std::vector<Vertex> distances;

    public:
    void execute(const Graph& graph, Vertex startVertex) override;
    void print(const Display& display, std::ostream& out) const override;
    const std::vector<Vertex>& getDistances() const { return distances; }
};

#endif // BFS_HPP

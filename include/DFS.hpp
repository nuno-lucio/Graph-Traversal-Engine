/**********
 * Traverses Graph with Iterative Depth-First-Search Algorithm
 * Author: Nuno Lucio
 **********/

#ifndef DFS_HPP
#define DFS_HPP

#include "GraphAlgorithm.hpp"
#include <stack>

using Index = unsigned int;

constexpr unsigned int START_INDEX = 0;

class DFS : public GraphAlgorithm
{
    private:
    std::vector<Vertex> discoveryTimes;
    std::vector<Vertex> finalTimes;

    struct Frame
    {
        Vertex vertex;
        Index nextNeighborIndex;
    };

    void visit(const Graph &graph, std::stack<Frame> &stack, unsigned int &current_time);

    public:
    void execute(const Graph& graph, Vertex startVertex) override;
    const std::vector<Vertex>& getDiscoveryTimes() const { return discoveryTimes; }
    const std::vector<Vertex>& getFinalTimes() const { return finalTimes; }
    void print(const Display& display, std::ostream& out) const override;
};

#endif // DFS_HPP

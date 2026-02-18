/**********
 * Traverses Graph with Iterative Depth-First-Search Algorithm
 * Author: Nuno Lucio
 **********/

#include "DFS.hpp"

#include "Display.hpp"

void DFS::visit(const Graph& graph, std::stack<Frame>& stack, unsigned int& current_time)
{
    while(!stack.empty())
    {
        unsigned int vertex = stack.top().vertex;
        unsigned int nextNeighborIndex = stack.top().nextNeighborIndex;
        stack.pop();

        if(discoveryTimes[vertex] == NOT_VISITED)
        {
            current_time++;
            discoveryTimes[vertex] = current_time;
        }

        if(nextNeighborIndex < graph.getNeighbors(vertex).size())
        {
            // Push current vertex to stack to continue to next neighbor
            Frame frame;
            frame.vertex = vertex;
            frame.nextNeighborIndex = nextNeighborIndex + 1;
            stack.push(frame);

            Vertex neighbor = graph.getNeighbors(vertex)[nextNeighborIndex];

            if(discoveryTimes[neighbor] == 0)
            {
                // Visit current neighbor
                parents[neighbor] = vertex;
                frame.vertex = neighbor;
                frame.nextNeighborIndex = START_INDEX;
                stack.push(frame);
            }
        }
        else
        {
            current_time++;
            finalTimes[vertex] = current_time;
        }
    }
}

void DFS::execute(const Graph& graph, Vertex startVertex)
{
    std::stack<Frame> stack;
    Frame frame;
    unsigned int current_time = 0;
    const unsigned int nVertices = graph.getNumberOfVertices();

    // Initiliaze
    discoveryTimes.assign(nVertices, NOT_VISITED);
    finalTimes.assign(nVertices, NOT_VISITED);
    parents.assign(nVertices, NO_PARENT);

    // Start at initial vertex
    frame.vertex = startVertex;
    frame.nextNeighborIndex = START_INDEX;
    stack.push(frame);

    visit(graph, stack, current_time);

    // Check unexplored vertices
    for (std::size_t v = 0; v < nVertices; v++)
    {
        if(discoveryTimes[v] == 0)
        {
            frame.vertex = v;
            frame.nextNeighborIndex = START_INDEX;
            stack.push(frame);
            visit(graph, stack, current_time);
        }
    }
}

void DFS::print(const Display& display, std::ostream& out) const
{
    display.printResults(*this, out);
}

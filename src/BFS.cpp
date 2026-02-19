/**********
 * Traverses Graph with Iterative Breadth-First-Search Algorithm
 * Author: Nuno Lucio
 **********/

#include "BFS.hpp"
#include "Display.hpp"
#include <queue>

void BFS::execute(const Graph& graph, Vertex startVertex)
{
    // Initialize
    const Vertex nVertices = graph.getNumberOfVertices();
    distances.assign(nVertices, NO_DISTANCE);
    parents.assign(nVertices, NO_PARENT);
    std::queue<Vertex> q;

    // Push starting vertex into queue
    distances[startVertex] = 0;
    q.push(startVertex);

    // Visit all vertices in the queue
    while(!q.empty())
    {
        Vertex vertex = q.front();
        q.pop();

        // Update and visit each neighbor
        for(Vertex neighbor : graph.getNeighbors(vertex))
        {
            if(distances[neighbor] == NO_DISTANCE)
            {
                distances[neighbor] = distances[vertex] + 1;
                parents[neighbor] = vertex;
                q.push(neighbor);
            }
        }
    }
}

void BFS::print(const Display& display, std::ostream& out) const
{
    display.printResults(*this, out);
}

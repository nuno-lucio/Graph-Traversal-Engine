/**********
 * Graph representation
 * Author: Nuno Lucio
 **********/

#include "Graph.hpp"
#include <algorithm>

unsigned int Graph::getNumberOfVertices() const
{
    return nVertices;
}

unsigned int Graph::getNumberOfEdges() const
{
    unsigned int nEdges = 0;

    for (auto adjacencies : adjacencyList)
    {
        nEdges += adjacencies.size();
    }

    return isDirected ? nEdges : (nEdges / 2);
}

const std::vector<Vertex>& Graph::getNeighbors(Vertex v) const
{
    return adjacencyList.at(v);
}

bool Graph::isDirectedGraph() const
{
    return isDirected;
}

void Graph::addEdge(Vertex from, Vertex to)
{
    adjacencyList[from].push_back(to);
    if(!isDirected) adjacencyList[to].push_back(from);
}

void Graph::removeEdge(Vertex from, Vertex to)
{
    adjacencyList[from].erase(std::remove(adjacencyList[from].begin(), adjacencyList[from].end(), to),
        adjacencyList[from].end());

    if(!isDirected)
    {
        adjacencyList[to].erase(std::remove(adjacencyList[to].begin(), adjacencyList[to].end(), from),
            adjacencyList[to].end());
    }
}

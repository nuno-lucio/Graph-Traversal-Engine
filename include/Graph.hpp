/**********
 * Graph representation
 * Author: Nuno Lucio
 **********/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

using Vertex = unsigned int;

class Graph
{
    private:
    bool isDirected;
    unsigned int nVertices;
    std::vector<std::vector<Vertex>> adjacencyList;

    public:
    Graph(bool isDirected, unsigned int nVertices) : isDirected(isDirected), nVertices(nVertices)
    { adjacencyList.resize(nVertices, std::vector<Vertex>()); }

    Graph(bool isDirected, unsigned int nVertices, const std::vector<std::vector<Vertex>> &adjacencyList) :
    isDirected(isDirected), nVertices(nVertices), adjacencyList(adjacencyList) {}

    unsigned int getNumberOfVertices() const;
    unsigned int getNumberOfEdges() const;
    const std::vector<Vertex>& getNeighbors(Vertex v) const;
    bool isDirectedGraph() const;

    void addEdge(Vertex from, Vertex to);
    void removeEdge(Vertex from, Vertex to);
};

#endif // GRAPH_HPP

/**********
 * Produces Graphs
 * Author: Nuno Lucio
 **********/

#include "GraphFactory.hpp"

Graph GraphFactory::read(std::istream &in)
{
    unsigned int nVertices, nAdjacencyLists;
    bool isDirected;

    in >> nVertices >> nAdjacencyLists >> isDirected;
    Graph graph(isDirected, nVertices);

    for(size_t i = 0; i < nAdjacencyLists; i++)
    {
        Vertex from;
        unsigned int degree;
        in >> from >> degree;

        for(size_t j = 0; j < degree; j++)
        {
            Vertex to;
            in >> to;
            graph.addEdge(from, to);
        }
    }
    
    return graph;
}

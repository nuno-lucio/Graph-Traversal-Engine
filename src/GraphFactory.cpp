/**********
 * Produces Graphs
 * Author: Nuno Lucio
 **********/

#include "GraphFactory.hpp"
#include <stdexcept>

Graph GraphFactory::read(std::istream &in)
{
    unsigned int nVertices, nAdjacencyLists;
    bool isDirected;

    in >> nVertices >> nAdjacencyLists >> isDirected;

    if(in.fail())
    {
        throw std::runtime_error("Input stream failed while reading graph header. Invalid format. ");
    }

    Graph graph(isDirected, nVertices);

    for(size_t i = 0; i < nAdjacencyLists; i++)
    {
        Vertex from;
        unsigned int degree;
        in >> from >> degree;

        if(in.fail())
        {
            throw std::runtime_error("Input stream failed while reading adjacency list " + std::to_string(i));
        }

        if(from >= nVertices)
        {
            throw std::out_of_range("Origin vertex " + std::to_string(from) + " does not exist in the graph!");
        }

        for(size_t j = 0; j < degree; j++)
        {
            Vertex to;
            in >> to;

            if(in.fail())
            {
                throw std::runtime_error("Input stream failed while reading neighbors from vertex " + std::to_string(from));
            }

            if(to >= nVertices)
            {
                throw std::out_of_range("Destination vertex " + std::to_string(to) + " does not exist in the graph!");
            }

            graph.addEdge(from, to);
        }
    }
    
    return graph;
}

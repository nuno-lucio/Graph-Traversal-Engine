/**********
 * Displays graph traversal results
 * Author: Nuno Lucio
 **********/

#include "Display.hpp"
#include <vector>

void Display::printResults(const DFS& dfs, std::ostream& out) const
{
    const std::vector<Vertex> &discoveryTimes = dfs.getDiscoveryTimes();
    const std::vector<Vertex> &finalTimes = dfs.getFinalTimes();
    const std::vector<Vertex> &parents = dfs.getParents();

    out << "Discovery Times: " << std::endl;
    for (size_t i = 0; i < discoveryTimes.size(); i++)
    {
        out << i << " ---> " << discoveryTimes[i] << std::endl;
    }
    out << std::endl;

    out << "Final Times: " << std::endl;
    for (size_t i = 0; i < finalTimes.size(); i++)
    {
        out << i << " ---> " << finalTimes[i] << std::endl;
    }
    out << std::endl;

    out << "Parents: " << std::endl;
    for (size_t i = 0; i < parents.size(); i++)
    {
        if(parents[i] == NO_PARENT)
        {
            out << i << " ---> " << "None" << std::endl;
        }
        else
        {
            out << i << " ---> " << parents[i] << std::endl;
        }
    }
}

void Display::printResults(const BFS& bfs, std::ostream& out) const
{
    const std::vector<Vertex> &distances = bfs.getDistances();
    const std::vector<Vertex> &parents = bfs.getParents();

    out << "Distances: " << std::endl;
    for (size_t i = 0; i < distances.size(); i++)
    {
        if(distances[i] == NO_DISTANCE)
        {
            out << i << " ---> " << "Infinity" << std::endl;
        }
        else
        {
            out << i << " ---> " << distances[i] << std::endl;
        }
    }
    out << std::endl;

    out << "Parents: " << std::endl;
    for (size_t i = 0; i < parents.size(); i++)
    {
        if(parents[i] == NO_PARENT)
        {
            out << i << " ---> " << "None" << std::endl;
        }
        else
        {
            out << i << " ---> " << parents[i] << std::endl;
        }
    }
}

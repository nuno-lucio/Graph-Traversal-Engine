/**********
 * Produces Graphs from file
 * Author: Nuno Lucio
 **********/

#include "GraphFileFactory.hpp"

#include <fstream>

Graph GraphFileFactory::createGraph()
{
    std::ifstream file(filename);

    if(!file) throw std::runtime_error("Error opening file " + filename);
    
    return read(file);
}

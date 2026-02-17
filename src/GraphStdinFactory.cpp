/**********
 * Produces Graphs from standard input
 * Author: Nuno Lucio
 **********/

#include "GraphStdinFactory.hpp"

#include <iostream>

Graph GraphStdinFactory::createGraph()
{   
    return read(std::cin);
}

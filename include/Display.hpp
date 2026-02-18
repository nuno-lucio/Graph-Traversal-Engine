/**********
 * Displays graph traversal results
 * Author: Nuno Lucio
 **********/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "DFS.hpp"
#include <ostream>

class Display
{
    public:
    virtual ~Display() = default;
    void printResults(const DFS &dfs, std::ostream &out) const;
};

#endif // DISPLAY_HPP

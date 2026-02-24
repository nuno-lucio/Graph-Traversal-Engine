/**********
 * Test Display
 * Author: Nuno Lucio
 **********/

#include <gtest/gtest.h>
#include "Display.hpp"
#include "DFS.hpp"
#include <sstream>

TEST(DisplayTest, OutputTest)
{
    // Setup
    Graph g(true, 1);
    DFS dfs;
    dfs.execute(g, 0);
    std::stringstream displayOutput;
    Display display;

    // Action
    display.printResults(dfs, displayOutput);

    // Check
    std::string expectedOutput = "Discovery Times: \n"
        "0 ---> 1\n\n"
        "Final Times: \n"
        "0 ---> 2\n\n"
        "Parents: \n"
        "0 ---> None\n";
    EXPECT_EQ(displayOutput.str(), expectedOutput);
}

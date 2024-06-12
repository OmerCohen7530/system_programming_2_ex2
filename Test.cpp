#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

// g1+g2
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g3.toString() == expected.toString());
}

//g1-g2
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g3.toString() == expected.toString());
}

//g1+=g2
TEST_CASE("Test graph addition and assignment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

//g1-=g2
TEST_CASE("Test graph subtraction and assignment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 -= g2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

//g1*scalar
TEST_CASE("Test graph multiplication by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 = g1 * -2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, -2, 0},
        {-2, 0, -2},
        {0, -2, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

//g1*=scalar
TEST_CASE("Test graph multiplication by scalar and assignment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 *= -2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, -2, 0},
        {-2, 0, -2},
        {0, -2, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

//g1/scalar
TEST_CASE("Test graph division by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 = g1 / 2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

//g1/=scalar
TEST_CASE("Test graph division by scalar and assignment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 /= 2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g1.toString() == expected.toString());
}

// g1*g2
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 4, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {2, 2, 2},
        {1, 6, 1},
        {1, 4, 3}};
    expected.loadGraph(expectedGraph);
    CHECK(g3.toString() == expected.toString());
}

// g1==g2
TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 2},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 == g2);
    CHECK(&g1 != &g2);
}

// g1!=g2
TEST_CASE("Test graph inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 != g2);
}

// g1 < g2
TEST_CASE("Test graph less than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 < g2);
}

// g1 > g2
TEST_CASE("Test graph greater than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g2 > g1);
}

// g1 <= g2
TEST_CASE("Test graph less than or equal to")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 <= g2);
}

// g1 >= g2
TEST_CASE("Test graph greater than or equal to")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g2 >= g1);
}

// g1++ (postfix)
TEST_CASE("Test graph postfix increment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 1},
        {1, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g2.toString() == expected.toString());
}

// ++g1 (prefix)
TEST_CASE("Test graph prefix increment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = ++g1;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {1, 2},
        {2, 1}};
    expected.loadGraph(expectedGraph);
    CHECK(g2.toString() == expected.toString());
    CHECK(g1.toString() == g2.toString());
}

// g1-- (postfix)
TEST_CASE("Test graph postfix decrement")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2},
        {2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {0, 2},
        {2, 0}};
    expected.loadGraph(expectedGraph);
    CHECK(g2.toString() == expected.toString());
}

// --g1 (prefix)
TEST_CASE("Test graph prefix decrement")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2},
        {2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = --g1;
    ariel::Graph expected;
    vector<vector<int>> expectedGraph = {
        {-1, 1},
        {1, -1}};
    expected.loadGraph(expectedGraph);
    CHECK(g2.toString() == expected.toString());
}

// g1 is a subgraph of g2
TEST_CASE("Test graph is a subgraph of another graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1.isSubGraph(g2));
}

// g1 is not a subgraph of g2
TEST_CASE("Test graph is not a subgraph of another graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 1}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(weightedGraph);
    CHECK_FALSE(g1.isSubGraph(g2));
}

// g/0
TEST_CASE("Test division by zero")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);
    CHECK_THROWS(g1 /= 0);
}

// extreme case of empty graph
TEST_CASE("Test empty graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {};
    CHECK_THROWS(g1.loadGraph(graph));
}

// extreme case of no edges
TEST_CASE("Test graph with no edges")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 0},
        {0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1.isSubGraph(g2));
}

// extreme case of one vertex
TEST_CASE("Test graph with one vertex")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK(g1 < g2);
}

// is contains cycle after operations
TEST_CASE("Test graph contains cycle")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g1.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g1) == "0->1->2->0");
    g1 = g1*50;
    CHECK(ariel::Algorithms::isContainsCycle(g1) == "0->1->2->0");
}

// is connected after operations
TEST_CASE("Test graph is connected")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {1, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK_FALSE(ariel::Algorithms::isConnected(g1));
    g1 = g1 + g2;
    CHECK(ariel::Algorithms::isConnected(g1));
    -g1;
    CHECK(ariel::Algorithms::isConnected(g1));
}

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.toString() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g4.toString() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
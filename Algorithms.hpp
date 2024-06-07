// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stdexcept>

namespace ariel
{
    class Algorithms
    {
        public:

        // Bellman-Ford algorithm
        static string BellmanFord(Graph& g, int start, int end);

        // Dijkstra algorithm
        static string Dijkstra(Graph& g, int start, int end);

        // BFS algorithm
        static void bfs(const vector<vector<int>>& graph, vector<int>& visited, int node);

        // DFS algorithm
        static bool dfs(int current, const vector<vector<int>>& graph, vector<int>& visited, vector<int>& parent, string& cycle);

        // make the directed graph to undirected
        static void help_make_directed_to_undirected(vector<vector<int>>& graph);

        // make deep copy of the graph
        static vector<std::vector<int>> deep_copy_of_graph(const vector<vector<int>>& graph);

        // Function to check if the graph is connected
        // return 1 : return 0
        static bool isConnected(Graph &g);

        // Function to check the shortest path between two nodes
        // return the path : return -1 :
        // return "invalid start or end node" :
        // return "ERROR: The graph contains a negative-weight cycle."
        static string shortestPath(Graph &g, int start, int end);

        // Function to check if the graph is contains a cycle
        // return the cycle : return 0
        static string isContainsCycle(Graph &g);

        // Function to check if the graph is bipartite
        // return the bipartite : return 0
        static string isBipartite(Graph &g);

        // Function to check if the graph is contains a negative cycle
        // return the negative cycle : return 0
        static string negativeCycle(Graph &g);
    };
}

#endif // ALGORITHMS_HPP
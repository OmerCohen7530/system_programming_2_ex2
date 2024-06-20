// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "Algorithms.hpp"

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <string>
#include <stack>

#define INT_MAX std::numeric_limits<int>::max()

using namespace std;
using namespace ariel;


string Algorithms::BellmanFord(Graph& g, int start, int end)
{
    size_t numVertices = g.getMatrix().size();
    vector<int> dis(numVertices, INT_MAX);
    vector<int> prev(numVertices, -1);
    dis[(size_t)start] = 0;
    vector<vector<int>> graph = g.getMatrix();

    // Relax edges repeatedly V - 1 times
    for (size_t i = 0; i < numVertices - 1; i++){
        for (size_t j = 0; j < numVertices; j++){
            for (size_t k = 0; k < numVertices; k++){
                if (graph[j][k] != 0 && dis[j] != INT_MAX && dis[j] + graph[j][k] < dis[k]){
                    dis[k] = dis[j] + graph[j][k];
                    prev[k] = j;
                }
            }
        }
    }

    // Check for negative cycles;
    for (size_t j = 0; j < numVertices; j++){
        for (size_t k = 0; k < numVertices; k++){
            if (graph[j][k] != 0 && dis[j] != INT_MAX && dis[j] + graph[j][k] < dis[k]){
                return "ERROR: The graph contains a negative-weight cycle.";
            }
        }
    }

    // If there is no path from start to end
    if (dis[(size_t)end] == INT_MAX){
        return "-1";
    }

    // Build path
    string path = to_string(end);
    for (size_t v = (size_t)end; v != (size_t)start; v = (size_t)prev[v]){
        path.insert(0, to_string((int)prev[v]) + "->");
    }

    return path;
}

string Algorithms::Dijkstra(Graph& g, int start, int end)
{
    const vector<vector<int>>& graph = g.getMatrix();
        size_t numVertices = graph.size();
        vector<int> dis(numVertices, INT_MAX);
        vector<int> prev(numVertices, -1);
        vector<int> visited(numVertices, 0);
        dis[(size_t)start] = 0;
        std::stringstream ss;

        for (size_t i = 0; i < numVertices; i++) {
            int minDist = INT_MAX;
            int minIndex = -1;

            for (size_t j = 0; j < numVertices; j++) {
                if (!visited[j] && dis[j] < minDist) {
                    minDist = dis[j];
                    minIndex = j;
                }
            }

            if (minIndex == -1) {
                break;
            }

            visited[(size_t)minIndex] = 1;

            for (size_t j = 0; j < numVertices; j++) {
                if (graph[(size_t)minIndex][j] != 0 && dis[(size_t)minIndex] + graph[(size_t)minIndex][j] < dis[j]) {
                    dis[j] = dis[(size_t)minIndex] + graph[(size_t)minIndex][j];
                    prev[j] = minIndex;
                }
            }
        }

        if (dis[(size_t)end] == INT_MAX) {
            ss << "-1";

        } else {
            vector<int> path;
            for (int at = end; at != -1; at = prev[(size_t)at]) {
                path.push_back(at);
            }
            if (!path.empty()) {
                for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i) {
                    ss << path[(size_t)i];
                    if (i > 0) {
                        ss << "->";
                    }
                }
            }       
            
        
        }
        return ss.str();
}

void Algorithms::bfs(const vector<vector<int>>& graph, vector<int>& visited, int node)
{
    std::queue<int> q;
        visited[(size_t)node] = 1;
        q.push(node);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (size_t i = 0; i < graph[(size_t)current].size(); i++) {
                if (graph[(size_t)current][i] != 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
}

bool Algorithms::dfs(int current, const vector<vector<int>>& graph, vector<int>& visited, vector<int>& parent, string& cycle)
{
    visited[(size_t)current] = 1; // Mark as visited

        for (size_t neighbor = 0; neighbor < graph[(size_t)current].size(); neighbor++) {
            if (graph[(size_t)current][neighbor] == 0) {
                continue; // No edge between current and neighbor
            }

            if (visited[neighbor] == 0) { // Not visited
                parent[neighbor] = current;
                if (dfs(neighbor, graph, visited, parent, cycle)) {
                    return true;
                }
            } else if (visited[neighbor] == 1 && (size_t)parent[(size_t)current] != neighbor) { // Cycle found
                std::stringstream ss;
                vector<int> path;
                ss << neighbor;
                int node = current;
                while ((size_t)node != neighbor) { // Construct the cycle string
                    path.push_back(node);
                    //ss << "->" << node;
                    node = parent[(size_t)node];
                }
                //for loop to insert all path to ss
                if (!path.empty()) {
                    for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i) {
                        ss << "->" << path[(size_t)i];
                    }
                }
                ss << "->" << neighbor;
                cycle = ss.str();
                return true;
            }
        }
        visited[(size_t)current] = 2; // Fully processed
        return false;
}

void Algorithms::help_make_directed_to_undirected(vector<vector<int>>& graph)
{
    for (size_t i = 0; i < graph.size(); i++) {
            for (size_t j = 0; j < graph[i].size(); j++) {
                if (i != j && graph[i][j] != 0) {
                    graph[j][i] = graph[i][j];
                }
            }
        }
}

vector<vector<int>> Algorithms::deep_copy_of_graph(const vector<vector<int>>& graph)
{
    std::vector<std::vector<int>> copy(graph.size());
        for (size_t i = 0; i < graph.size(); ++i) {
            copy[i] = graph[i];  // Shallow copy of inner vectors
        }

        // Make a deep copy of inner vectors (important for graphs)
        for (size_t i = 0; i < graph.size(); ++i) {
            copy[i].resize(graph[i].size());  // Ensure inner vectors have correct size
            for (size_t j = 0; j < graph[i].size(); ++j) {
                copy[i][j] = graph[i][j];  // Copy individual elements
            }
        }
        return copy;
}

bool Algorithms::isConnected(Graph &g)
{
    vector<int> visited(g.getMatrix().size(), 0);
        bool ans = true;
        if(!g.getIsDirected())
        {
            bfs(g.getMatrix() , visited , 0);
            for(size_t i=0; i<g.getMatrix().size(); i++)
                if(visited[i] == 0)
                    ans = false;
        }
        else
        {
            for(size_t i=0; i<g.getMatrix().size(); i++) {
                visited = std::vector<int>(g.getMatrix().size(), 0);
                bfs(g.getMatrix() , visited , i);
                for(size_t i=0; i<g.getMatrix().size(); i++)
                    if(visited[i] == 0)
                        ans = false;
            }
        }
        return ans;
}

string Algorithms::shortestPath(Graph &g, int start, int end)
{
    // Check if the start and end nodes are valid
        if(start < 0 || (size_t)start >= g.getMatrix().size() || end < 0 || (size_t)end >= g.getMatrix().size()) {
            return "invalid start or end node";
        }


        if (!g.getIsNegativeEdges()) {
            return Dijkstra(g, start, end);
        } else {
            return BellmanFord(g, start,end);
        }
}

string Algorithms::isContainsCycle(Graph &g)
{
    const std::vector<std::vector<int>>& graph = g.getMatrix();
        std::vector<int> visited(graph.size(), 0);
        std::vector<int> parent(graph.size(), -1);
        std::string cycle = "";

        for (size_t i = 0; i < graph.size(); i++) {
            if (visited[i] == 0) { // Not visited
                if (dfs(i, graph, visited, parent, cycle)) {
                    return cycle;
                }
            }
        }
        return "0"; // No cycle found
}

string Algorithms::isBipartite(Graph &g)
{
    size_t n = g.getMatrix().size();
    vector<vector<int>> graph = g.getMatrix();

    // Make a deep copy of the graph and make it undirected
    vector<std::vector<int>> temp = deep_copy_of_graph(graph);
    help_make_directed_to_undirected(temp);


    vector<int> color(n, -1);      // -1 = no color;
    vector<vector<int>> groups(2); // groups[0] and groups[1] are the two groups of vertices

    for (size_t start = 0; start < n; ++start){
        if (color[start] == -1){
            queue<int> q;
            q.push(start);
            color[start] = 0;
            groups[0].push_back(start);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (size_t i = 0; i < n; ++i){
                    if (temp[(size_t)node][i] != 0)
                    {
                        if (color[i] == -1)
                        {
                            // If the node has not been colored, color it with the opposite color of the current node
                            color[i] = 1 - color[(size_t)node];
                            groups[(size_t)color[i]].push_back(i);
                            q.push(i);
                        }
                        else if (color[i] == color[(size_t)node])
                        {
                            // If the node has the same color as the current node, the graph is not bipartite
                            return "0";
                        }
                    }
                }
            }
        }
    }

    string ans = "The graph is bipartite: A={";
    for (size_t i = 0; i < groups[0].size(); ++i)
    {
        ans += to_string(groups[0][i]);
        if (i != groups[0].size() - 1)
        {
            ans += ", ";
        }
    }
    ans += "}, B={";
    for (size_t i = 0; i < groups[1].size(); ++i)
    {
        ans += to_string(groups[1][i]);
        if (i != groups[1].size() - 1)
        {
            ans += ", ";
        }
    }
    ans += "}.";
    return ans;
}

string Algorithms::negativeCycle(Graph &g)
{
    vector<vector<int>> graph = g.getMatrix();
        size_t numVertices = graph.size();
        std::vector<int> dis(numVertices, INT_MAX);
        std::vector<int > parent(numVertices, INT_MAX);
        int source = 0;  // Let's take 0 as the source node
        dis[(size_t)source] = 0;

        //realx edges repeatedly V - 1 times
        for (size_t j = 0; j < numVertices; j++) {
            for (size_t k = 0; k < numVertices; k++) {
                if (graph[j][k] != 0 && dis[j] != INT_MAX && dis[j] + graph[j][k] < dis[k]) {
                    if(!g.getIsDirected())
                        if((size_t)parent[j] == k)
                            continue;
                    dis[k] = dis[j] + graph[j][k];
                    parent[k] = j;
                }
            }
        }

        // Check for negative-weight cycles
        for (size_t v = 0; v < numVertices; v++) {
            std::vector<int> neighbors = g.getNeighbors(v);
            for (int neighbor : neighbors) {
                int weight = graph[v][(size_t)neighbor];
                if (dis[v] != INT_MAX && dis[v] + weight < dis[(size_t)neighbor]) {

                    // Construct the cycle
                    vector<int> cycle;
                    int current = neighbor;
                    do {
                        cycle.push_back(current);
                        current = parent[(size_t)current];
                    } while (current != neighbor && current != INT_MAX);

                    cycle.push_back(neighbor);
                    std::reverse(cycle.begin(), cycle.end());

                    // Construct the cycle string
                    string ans;
                    for (size_t i = 0; i < cycle.size(); ++i) {
                        ans += std::to_string(cycle[i]);
                        if (i != cycle.size() - 1) {
                            ans += "->";
                        }
                    }
                    return ans;
                }
            }
        }
        return "0"; // No negative cycle found
}
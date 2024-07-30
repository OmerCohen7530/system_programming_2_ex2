// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> matrix;
        bool isDirected;
        bool isNegativeEdges;

        // check if the graph has negative edges
        bool is_negative_edges_help(const vector<vector<int>>& graph);

        // check if the graph is directed or not
        bool is_simetric_help(const vector<vector<int>>& graph);

    public:
        size_t size;

        // constructors
        Graph(size_t n) : matrix(n, std::vector<int>(n, 0)) {}
        Graph() : matrix(0, std::vector<int>(0, 0)) {}

        // upadate the member variables
        void updateMembers();
        
        // build the graph with the given matrix
        void loadGraph(const vector<vector<int>>& graph);

        // print the graph
        void printGraph();

        // get the neighbors of the given vertex
        vector<int> getNeighbors(int vertex);

        //getters
        vector<vector<int>> getMatrix() const;
        bool getIsDirected();
        bool getIsNegativeEdges();

        //setters
        void setIsDirected(bool isDirected){
            this->isDirected = isDirected;
        }
        void setIsNegativeEdges(bool isNegativeEdges){
            this->isNegativeEdges = isNegativeEdges;
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        // Declaration of the operators
        
        // arritmatics operators
        Graph operator+(const Graph& other) const; // g1 + g2
        Graph& operator+=(const Graph& other); // g1 += g2
        Graph operator+() const; // +g
        Graph operator-(const Graph& other) const; // g1 - g2
        Graph& operator-=(const Graph& other); // g1 -= g2
        Graph operator-() const; // -g

        // comparison operators
        bool operator==(const Graph& other) const; // g1 == g2
        bool operator!=(const Graph& other) const; // g1 != g2
        bool operator<(const Graph& other) const; // g1 < g2
        bool operator<=(const Graph& other) const; // g1 <= g2
        bool operator>(const Graph& other) const; // g1 > g2
        bool operator>=(const Graph& other) const; // g1 >= g2

        // increment and decrement operators
        Graph& operator++(); // Prefix increment: ++g
        Graph operator++(int); // Postfix increment: g++
        Graph& operator--(); // Prefix decrement: --g
        Graph operator--(int); // Postfix decrement: g--

        // assignment operators
        Graph operator*(int scalar) const; // g * 2
        Graph operator*(const Graph& other) const; // g1 * g2
        Graph& operator*=(int scalar); // g *= 2
        Graph operator/(double scalar) const; // g / 2.0
        Graph& operator/=(double scalar); // g /= 2.0


        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
        string toString() const;

        int isSubGraph(const Graph& other) const;

        size_t countOfEdges() const;
        
        };
} // namespace ariel

#endif // GRAPH_HPP
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
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator+() const;
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator-() const;

        // comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // increment and decrement operators
        Graph& operator++(); // Prefix increment
        Graph operator++(int); // Postfix increment
        Graph& operator--(); // Prefix decrement
        Graph operator--(int); // Postfix decrement

        // assignment operators
        Graph operator*(int scalar) const;
        Graph operator*(const Graph& other) const;
        Graph& operator*=(int scalar);
        Graph operator/(double scalar) const;
        Graph& operator/=(double scalar);


        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
        string toString() const;

        int isSubGraph(const Graph& other) const;

        size_t countOfEdges() const;
        
        };
} // namespace ariel

#endif // GRAPH_HPP
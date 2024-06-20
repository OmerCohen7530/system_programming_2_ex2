// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace ariel;

Graph Graph::operator+(const Graph& other) const
{
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size");
    }
    Graph result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    result.updateMembers();
    return result;
}

Graph& Graph::operator+=(const Graph& other)
{
    Graph result = *this;
    *this = result + other;
    (*this).updateMembers();
    return *this;
}

Graph Graph::operator+() const
{
    return *this;
}

Graph Graph::operator-(const Graph& other) const
{
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size");
    }
    Graph result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    result.updateMembers();
    return result;
}

Graph& Graph::operator-=(const Graph& other)
{
    Graph result = *this;
    *this = result - other;
    (*this).updateMembers();
    return *this;

}

Graph Graph::operator-() const
{
    Graph result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i][j] = -matrix[i][j];
        }
    }
    result.updateMembers();
    return result;

}

// comparison operators
bool Graph::operator==(const Graph& other) const
{
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;

}

bool Graph::operator!=(const Graph& other) const
{
    return !(*this == other);

}

bool Graph::operator<(const Graph& other) const
{
    if(*this == other)
    {
        return false;
    }
    if(isSubGraph(other) == 1)
    {
        return true;
    }
    if (other.isSubGraph(*this) == 0)
    {
        if(this->countOfEdges() < other.countOfEdges())
        {
            return true;
        }
        if(this->countOfEdges() == other.countOfEdges())
        {
            return (this->size < other.size);
        }
    }
    return false;
}

bool Graph::operator<=(const Graph& other) const
{
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const
{
    return !(*this <= other);
}

bool Graph::operator>=(const Graph& other) const
{
    return !(*this < other);
}

// increment and decrement operators
Graph& Graph::operator++()
{
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j]++;
        }
    }
    (*this).updateMembers();
    return *this;
}

Graph Graph::operator++(int)
{
    Graph result = *this;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j]++;
        }
    }
    (*this).updateMembers();
    return result;
}

Graph& Graph::operator--()
{
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j]--;
        }
    }
    (*this).updateMembers();
    return *this;

}

Graph Graph::operator--(int)
{
    Graph result = *this;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j]--;
        }
    }
    (*this).updateMembers();
    return result;

}

// assignment operators
Graph Graph::operator*(int scalar) const
{
    Graph result = *this;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i][j] *= scalar;
        }
    }
    result.updateMembers();
    return result;
}

Graph Graph::operator*(const Graph& other) const{
    if (size != other.size) {
        throw std::invalid_argument("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }
    Graph result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    result.updateMembers();
    return result;
}

Graph& Graph::operator*=(int scalar)
{
    Graph result = *this;
    *this = result * scalar;
    (*this).updateMembers();
    return *this;

}

Graph Graph::operator/(double scalar) const
{
    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    Graph result = *this;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i][j] /= scalar;
        }
    }
    result.updateMembers();
    return result;

}

Graph& Graph::operator/=(double scalar)
{
    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    Graph result = *this;
    *this = result / scalar;
    (*this).updateMembers();
    return *this;

}

namespace ariel
{
    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        for (size_t i = 0; i < graph.size; i++) {
            os << "[";
            for (size_t j = 0; j < graph.matrix[i].size(); j++) {
                os << graph.matrix[i][j];
                if (j < graph.matrix[i].size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            if (i < graph.matrix.size() - 1) {
                os << "\n";
            }
        }
        return os << std::endl;
    }
    string Graph::toString() const
    {
        string str = "";
        for (size_t i = 0; i < size; i++) {
            str += "[";
            for (size_t j = 0; j < matrix[i].size(); j++) {
                str += to_string(matrix[i][j]);
                if (j < matrix[i].size() - 1) {
                    str += ", ";
                }
            }
            str += "]";
            if (i < matrix.size() - 1) {
                str += "\n";
            }
        }
        return str;
    }
}

void Graph::updateMembers()
{
    this->setIsDirected(!(is_simetric_help(this->matrix)));
    this->setIsNegativeEdges(is_negative_edges_help(this->matrix));
    this->size = this->matrix.size();
}

int Graph::isSubGraph(const Graph& other) const
{
    if ((*this).countOfEdges() > other.countOfEdges())
    {
        return false;
    }
    vector<vector<int>> matrix = (*this).getMatrix();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (matrix[i][j] != 0 && matrix[i][j] != other.getMatrix()[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

size_t Graph::countOfEdges() const
{
    size_t numEdges = 0; // Initialize edge count
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0) {
                numEdges++;
            }
        }
    }
    return numEdges;
}

bool Graph::is_negative_edges_help(const vector<vector<int>>& graph)
{
    for (size_t i = 0; i < graph.size(); i++) {
            for (size_t j = 0; j < graph[i].size(); j++) {
                if(graph[i][j] < 0)
                    return true;
            }
        }
        return false;
}

bool Graph::is_simetric_help(const vector<vector<int>>& graph)
{
    for (size_t i = 0; i < graph.size(); i++) {
            for (size_t j = 0; j < graph[i].size(); j++) {
                if (i != j && graph[i][j] != graph[j][i]) {
                    return false;
                }
            }
        }
        return true;
}

void Graph::loadGraph(const vector<vector<int>> &graph)
{
    if (graph.empty()) {
            throw std::invalid_argument("Invalid graph: The graph cannot be empty");
        }
        int n = graph.size();
        for (const auto& row : graph) {
            if (row.size() != (size_t)n) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        for (size_t j = 0; j < n; j++) {
            if (matrix[j][j] == 0) {
                throw std::invalid_argument("Invalid graph: non zero on diagonal");
            }
        }
        this->matrix = graph;
        this->isDirected = !(is_simetric_help(this->matrix));
        this->isNegativeEdges = is_negative_edges_help(this->matrix);
        this->size = (size_t)n;
}

void Graph::printGraph()
{
    // print of excercise #1
    int numVertices = this->matrix.size(); // Number of vertices in the graph
        int numEdges = 0; // Initialize edge count

        // Count the number of edges
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) {
                    if (isDirected || i < j) { // Avoid double-counting for undirected graphs
                        numEdges++;
                    }
                }
            }
        }

        // Print the details of the graph
        cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges. " ;
        cout << "this graph is " << (this->isDirected ? "undirected" : "directed") << "." << endl;
    
}

vector<int> Graph::getNeighbors(int vertex)
{
    vector<int> neighbors;
        for (size_t i = 0; i < this->matrix[static_cast<size_t>(vertex)].size(); i++) {
            if (this->matrix[static_cast<size_t>(vertex)][i] != 0) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
}

vector<vector<int>> Graph::getMatrix() const
{
    return this->matrix;
}

bool Graph::getIsDirected()
{
    return this->isDirected;
}

bool Graph::getIsNegativeEdges()
{
    return this->isNegativeEdges;
}

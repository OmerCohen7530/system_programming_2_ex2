## omer cohen
## omer7530@gmail.com
# Implementation of operators on Graph Class 
## Introduction
This project consists of a C++ implementation of a graph class (Graph) with various functionalities for graph manipulation and operations. It includes overloaded operators to perform arithmetic operations, comparison, subset checking, and increment/decrement on graphs.

## Functions
1. loadGraph(vector<vector<int>> graph): Loads a graph represented by an adjacency matrix provided as a 2D vector of integers.

2. operator<<(ostream& os, const Graph& g): Overloaded stream insertion operator to print the adjacency matrix of the graph.

3. toString() const: Converts the adjacency matrix of the graph into a string format.

4. Arithmetic Operations:

- Addition (operator+): Adds two graphs element-wise.
- Addition Assignment (operator+=): Adds another graph to the current graph.
- Subtraction (operator-): Subtracts one graph from another element-wise.
- Subtraction Assignment (operator-=): Subtracts another graph from the current graph.
- Multiplication by Scalar (operator*, operator*=): Multiplies the graph by a scalar value.
- Division by Scalar (operator/, operator/=): Divides the graph by a scalar value.
- Matrix Multiplication (operator*): Multiplies two graphs as matrices.
5. Comparison Operations:

- Equality (operator==): Checks if two graphs are equal.
- Inequality (operator!=): Checks if two graphs are not equal.
- Subset (isSubsetOf, isProperSubsetOf): Checks if one graph is a subset or proper subset of another.
- Comparison (operator<, operator>, operator<=, operator>=): Compares the number of edges and matrix size of two graphs.
6. Increment and Decrement Operators:

- Pre-increment (operator++): Increments all elements of the graph.
- Post-increment (operator++(int)): Increments all elements of the graph (returns the original graph).
- Pre-decrement (operator--): Decrements all elements of the graph.
- Post-decrement (operator--(int)): Decrements all elements of the graph (returns the original graph).
7. printGraph(): Prints information about the graph, including the number of vertices and edges.

8. size() const: Returns the number of vertices in the graph.

9. getMatrix() const: Returns a constant reference to the adjacency matrix of the graph.

10. isDirected(): Checks if the graph is directed based on the presence of directed edges or differing edge weights.

### Running the Demo
To run the demo, execute the following command in the terminal:
- make demo

### Running Tests
To run tests, execute the following command in the terminal:
- make test

### Tests
The project includes more than 20 tests to ensure the correctness and robustness of the Graph class implementation. These tests cover various functionalities and edge cases to validate the behavior of the class.

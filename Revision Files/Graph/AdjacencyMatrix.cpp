#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

/**
 * Graph Implementation using Adjacency Matrix Representation in C++
 * 
 * This code provides an implementation of a graph data structure using adjacency matrix representation.
 * The GraphAdjMatrix class supports operations like adding edges, setting vertex names, printing the graph, BFS, and DFS.
 */

class GraphAdjMatrix {
private:
    int **adjMatrix;    // Adjacency matrix to store edge connections
    int numVertices;    // Number of vertices in the graph
    string *vertexNames;    // Array to store names of vertices

public:
    // Constructor to initialize a graph with n vertices
    GraphAdjMatrix(int n) : numVertices(n) {
        adjMatrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            adjMatrix[i] = new int[n];
            memset(adjMatrix[i], 0, sizeof(int) * n); // Initialize adjacency matrix with zeros
        }
        vertexNames = new string[n];
    }

    // Destructor to deallocate memory
    ~GraphAdjMatrix() {
        for (int i = 0; i < numVertices; ++i)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
        delete[] vertexNames;
    }

    // Function to add an edge between vertices u and v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // If undirected graph, add edge from v to u
    }

    // Function to set the name of a vertex
    void setVertexName(int v, const string& name) {
        vertexNames[v] = name;
    }

    // Function to print the graph
    void printGraph() {
        cout << "Adjacency Matrix Representation:" << endl;
        cout << "  ";
        for (int i = 0; i < numVertices; ++i) {
            cout << vertexNames[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << vertexNames[i] << " ";
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to perform Breadth-First Search (BFS) traversal starting from a given vertex
    void BFS(int startVertex) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i)
            visited[i] = false;

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Search (BFS): ";
        while (!q.empty()) {
            int currentVertex = q.front();
            cout << vertexNames[currentVertex] << " ";
            q.pop();

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        delete[] visited;
        cout << endl;
    }

    // Utility function for DFS traversal
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertexNames[vertex] << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[vertex][i] && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    // Function to perform Depth-First Search (DFS) traversal starting from a given vertex
    void DFS(int startVertex) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i)
            visited[i] = false;

        cout << "Depth-First Search (DFS): ";
        DFSUtil(startVertex, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    cout << endl;

    // Create a graph with 5 vertices
    GraphAdjMatrix graph(5);

    // Set names for the vertices
    graph.setVertexName(0, "A");
    graph.setVertexName(1, "B");
    graph.setVertexName(2, "C");
    graph.setVertexName(3, "D");
    graph.setVertexName(4, "E");

    // Add edges between vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    cout << endl;

    // Perform BFS starting from vertex 0
    graph.BFS(0);

    // Perform DFS starting from vertex 0
    graph.DFS(0);

    cout << endl;

    return 0;
}

/*
Saple Output:
    Adjacency Matrix Representation:
    A B C D E 
    A 0 1 0 0 1 
    B 1 0 1 1 0 
    C 0 1 0 1 0 
    D 0 1 1 0 1 
    E 1 0 0 1 0 

    Breadth-First Search (BFS): A B E C D 
    Depth-First Search (DFS): A B C D E 
*/
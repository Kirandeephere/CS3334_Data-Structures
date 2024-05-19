#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of a graph using adjacency list representation.
// It defines a class GraphAdjList to represent the graph and provides functionalities to add edges,
// set vertex names, print the adjacency list representation, and perform Breadth-First Search (BFS) and
// Depth-First Search (DFS) traversals. The program also includes a main function to create a sample graph
// with 5 vertices, set their names, add edges between them, print the adjacency list, and perform BFS and DFS
// traversals starting from a specified vertex.


// Node to store adjacent vertices in the adjacency list
struct AdjListNode {
    int dest;           // Destination vertex
    AdjListNode* next;  // Pointer to the next adjacent vertex
};

// Adjacency list for each vertex
struct AdjList {
    AdjListNode* head;  // Pointer to the head of the list
};

// Class for representing a graph using adjacency list
class GraphAdjList {
private:
    AdjList* array;     // Array of adjacency lists
    int numVertices;    // Number of vertices in the graph
    string* vertexNames;    // Array to store names of vertices

public:
    // Constructor to initialize the graph with a given number of vertices
    GraphAdjList(int n) : numVertices(n) {
        array = new AdjList[n];
        for (int i = 0; i < n; ++i)
            array[i].head = nullptr;
        vertexNames = new string[n];
    }

    // Destructor to deallocate memory
    ~GraphAdjList() {
        delete[] vertexNames;
        for (int i = 0; i < numVertices; ++i) {
            AdjListNode* current = array[i].head;
            while (current) {
                AdjListNode* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] array;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        // Create a new node for destination vertex
        AdjListNode* newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = nullptr;

        // Add new node to the beginning of the list
        newNode->next = array[src].head;
        array[src].head = newNode;

        // For undirected graph, add an edge from dest to src as well
        newNode = new AdjListNode;
        newNode->dest = src;
        newNode->next = nullptr;

        // Add new node to the beginning of the list
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    // Function to set the name of a vertex
    void setVertexName(int v, const string& name) {
        vertexNames[v] = name;
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adjacency list of vertex " << vertexNames[i] << ": ";
            AdjListNode* current = array[i].head;
            while (current) {
                cout << "-> " << vertexNames[current->dest];
                current = current->next;
            }
            cout << endl;
        }
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) {
        // Array to mark visited vertices
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i)
            visited[i] = false;

        // Queue for BFS traversal
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        // Perform BFS traversal
        cout << "Breadth-First Search (BFS): ";
        while (!q.empty()) {
            int currentVertex = q.front();
            cout << vertexNames[currentVertex] << " ";
            q.pop();

            // Visit adjacent vertices
            AdjListNode* temp = array[currentVertex].head;
            while (temp) {
                int adjVertex = temp->dest;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        cout << endl;
    }

    // Depth-First Search (DFS) utility function
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertexNames[vertex] << " ";

        // Visit adjacent vertices recursively
        AdjListNode* temp = array[vertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex])
                DFSUtil(adjVertex, visited);
            temp = temp->next;
        }
    }

    // Depth-First Search (DFS)
    void DFS(int startVertex) {
        // Array to mark visited vertices
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i)
            visited[i] = false;

        // Perform DFS traversal
        cout << "Depth-First Search (DFS): ";
        DFSUtil(startVertex, visited);
        cout << endl;
        delete[] visited;
    }
};

int main() {
    // Create a graph with 5 vertices
    GraphAdjList graph(5);

    cout << endl;

    // Set names of vertices
    graph.setVertexName(0, "A");
    graph.setVertexName(1, "B");
    graph.setVertexName(2, "C");
    graph.setVertexName(3, "D");
    graph.setVertexName(4, "E");

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    graph.printGraph();

    cout << endl;

    // Perform BFS from vertex 0
    graph.BFS(0);

    // Perform DFS from vertex 0
    graph.DFS(0);

    cout << endl;

    return 0;
}

/*
Sample Ooutput:
    Adjacency list of vertex A: -> E-> B
    Adjacency list of vertex B: -> D-> C-> A
    Adjacency list of vertex C: -> D-> B
    Adjacency list of vertex D: -> E-> C-> B
    Adjacency list of vertex E: -> D-> A

    Breadth-First Search (BFS): A E B D C 
    Depth-First Search (DFS): A E D C B 
*/
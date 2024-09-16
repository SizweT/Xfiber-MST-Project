// Sizwe Tafane Student number: 53846273
// 1. Hi
// 2. I have a c++ project that I need help with, do you know c++?
// 3. Municipality has asked a XFiber company to install fiber in a new neighborhood. But there are limitation and constraints. Can I give you the constraints? 
// 4. -The company is constrained to bury the fiber cable only along certain paths -Some of the paths might be more expensive -The cost is represented as a weight on the edge
// 5. Algorithm to use is Prim's Algorithm. 
// I made changes to main function by reading data from a file, I added file and string c++ libraries
// I added namespace std for ease of naming standard
// I added comment to my code for clarity and documentation


#include <iostream>
#include <vector>
#include <fstream> // Added file libraries for working with files
#include <sstream> // Added string library for working with strings
#include <limits.h>

using namespace std; // Added namespace for standard naming

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int minKey(vector<int>& key, vector<bool>& mstSet);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // Assuming undirected graph
}

// Utility function to find the vertex with minimum key value
int Graph::minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to implement Prim's Algorithm and return the MST
void Graph::primMST() {
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << " \n";
    }
}

int main() {
    ifstream inputFile("C:\\data\\fiberdata.txt"); // Open file for reading inputs c:\\data
    if (!inputFile) {
        cerr << "Unable to open file fiberdata.txt"; // message if the txt is not found
        return 1;
    }

    int V, E;
    inputFile >> V; // reading number of vertices
    inputFile >> E; // reading number of edges to add

    Graph g(V);

    int u, v, weight;
    for (int i = 0; i < E; i++) {
        inputFile >> u >> v >> weight; // reading the edges from the txt file
        g.addEdge(u, v, weight); // adding the edges to the graph
    }

    inputFile.close(); // closing the file

    g.primMST();

    return 0;
}

/*
DFS-Depth First Search
Uses Stack ADT
It is an recursive algorithm in comparison to iterative BFS algo
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nodes;
    vector<int> *edges;

public:
    Graph(int n)
    {
        nodes = n;
        edges = new vector<int>[nodes];
    }
    void addEdge(int x, int y, bool dir = false)
    {
        edges[x].push_back(y);
        if (!dir)
            edges[y].push_back(x);
    }

    void printList()
    {
        //iterate for every vertex
        for (int i = 0; i < nodes; i++)
        {
            cout << i << "--> ";
            //each connection for each vertex
            for (auto connected : edges[i])
                cout << connected << ", ";
            cout << endl;
        }
    }

    void DFS(int root_node)
    
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 7);
    g.printList();
    g.DFS(0);
    return 0;
}
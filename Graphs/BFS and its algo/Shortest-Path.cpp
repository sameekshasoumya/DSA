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

    void BFS(int root_node, int dest_node=-1)
    {
        queue<int> temp;
        vector<bool> visited(nodes + 1, false);
        vector<int> parent(nodes);
        vector<int> dist(nodes);
        parent[root_node]=root_node;
        dist[root_node]=0;
        temp.push(root_node);
        visited[root_node] = true;
        while (!temp.empty())
        {
            int i = temp.front();
            cout << i << " ";
            temp.pop();
            for (auto child : edges[i])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    parent[child] = i;
                    dist[child] = dist[i] + 1;
                    temp.push(child);
                }
            }
        }
        cout<<endl;
        for(int i=0;i<nodes;i++)
        cout<<"Shortest distance from source node "<<root_node<< " to destination node "<<i<<" is "<<dist[i]<<"\n";
        if(dest_node!=-1){
            int temp_dest = dest_node;
            while(temp_dest!=root_node)
            {
                cout<<temp_dest<<"--";
                temp_dest = parent[temp_dest];
            }
            cout<<root_node<<endl;
        }
    }
};

int main()
{
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 7);
    g.addEdge(8, 9);
    g.printList();
    g.BFS(0,9);
    return 0;
} 

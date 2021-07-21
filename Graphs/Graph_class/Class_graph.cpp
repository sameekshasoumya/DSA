#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nodes;
    vector<int> *edges;
public:
    Graph(int n)
    {
        nodes=n;
        edges= new vector<int>[nodes];
    }
    void addEdge(int x, int y, bool dir=false)
    {
        edges[x].push_back(y);
        if(!dir)
        edges[y].push_back(x);
    }
    
    void printList()
    {
        //iterate for every vertex
        for(int i=0;i<nodes;i++)
        {
            cout<<i<<"--> ";
            //each connection for each vertex
            for(auto connected:edges[i])
            cout<<connected<<", ";
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.printList();
    return 0;
}
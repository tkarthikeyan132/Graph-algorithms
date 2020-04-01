#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Vertex
{
    public:
    int topNum;
    int indeg;
    Vertex()
    {
        indeg=0;
    }
};
class Graph
{
    public:
    int V;
    int E;
    vector <int> adj[20];
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        
    }
};
Vertex ver[20];
int toparray[20]={0};
void topological_ordering(Graph G);
int main()
{
    Graph G;
    int x,y;
    cout<<"Enter the number of vertices:";
    cin>>G.V;
    cout<<"Enter the number of edges:";
    cin>>G.E;
    for(int w=0;w<G.E;w++)
    {
        cin>>x>>y;
        G.addEdge(x,y);
        ver[y].indeg++;
    }
    topological_ordering(G);
    for(int i=0;i<G.V;i++)
        cout<<toparray[i]<<" ";
    return 0;
}
void topological_ordering(Graph G)
{
    queue <int> q;
    int counter =0;
    for(int i=0;i<G.V;i++)
    {
        if(ver[i].indeg==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        ver[y].topNum = counter;
        toparray[counter]=y;
        counter++;
        for(int j=0;j<G.adj[y].size();j++)
        {
            ver[G.adj[y][j]].indeg--;
            if(ver[G.adj[y][j]].indeg==0)
                q.push(G.adj[y][j]);
        }
    }
    if(counter!=G.V)
        cout<<"cycle found !!"<<endl;
}
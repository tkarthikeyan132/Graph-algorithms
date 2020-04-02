#include"Module2.h"
using namespace std;
void DFS(Graph G)
{
    Vertex Vertex_Array[20]; // To store information about the vertex
    stack <int> q;
    q.push(0);
    Vertex_Array[0].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        cout<<t<<" ";
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                Vertex_Array[k->first].color=1;
            }
        }
    }
}
Graph DFS(Graph G,int s)
{
    Vertex Vertex_Array[20]; // To store information about the vertex
    stack <int> q;
    q.push(s);
    Graph T(G.V,G.V-1);
    Vertex_Array[s].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                if(G.directed==0)
                T.addUEdge(t,k->first,k->second);
                else
                T.addEdge(t,k->first,k->second);
                Vertex_Array[k->first].color=1;
            }
        }
    }
    T.directed=G.directed;
    return T;
}
bool DFS(Graph G,int s,int r)
{
    Vertex Vertex_Array[20]; // To store information about the vertex
    stack <int> q;
    q.push(s);
    Vertex_Array[s].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        if(t==r)
            return true;
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                Vertex_Array[k->first].color=1;
            }
        }
    }
    return false;
}
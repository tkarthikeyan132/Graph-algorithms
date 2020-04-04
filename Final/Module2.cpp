#include"Module2.h"
using namespace std;
void DFS(Graph &G)
{
    stack <int> q;
    q.push(0);
    G.Vertex_Array[0].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        cout<<t<<" ";
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(G.Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                G.Vertex_Array[k->first].color=1;
            }
        }
    }
}
Graph DFS(Graph &G,int s)
{
    stack <int> q;
    q.push(s);
    Graph T(G.V,G.V-1);
    G.Vertex_Array[s].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(G.Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                if(G.directed==0)
                T.addUEdge(t,k->first,k->second);
                else
                T.addEdge(t,k->first,k->second);
                G.Vertex_Array[k->first].color=1;
            }
        }
    }
    T.directed=G.directed;
    return T;
}
bool DFS(Graph &G,int s,int r)
{
    stack <int> q;
    q.push(s);
    G.Vertex_Array[s].color=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        if(t==r)
            return true;
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            if(G.Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                G.Vertex_Array[k->first].color=1;
            }
        }
    }
    return false;
}

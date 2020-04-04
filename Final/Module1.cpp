#include"Module1.h"
using namespace std;
void BFS(Graph G)
{
    Vertex Vertex_Array[20]; // To store information about the vertex
    queue <int> q;
    q.push(0);
    Vertex_Array[0].color=1;
    while(!q.empty())
    {
        int t=q.front();
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
Graph BFS(Graph G, int s)
{
    Graph T(G.V,G.V-1);
    queue <int> q;
    q.push(s);
    Vertex_Array[s].color=1;
    Vertex_Array[s].pid=-1; //NULL
    Vertex_Array[s].dist=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(auto k=G.adj[t].begin();k!=G.adj[t].end();k++)
        {
            if(Vertex_Array[k->first].color==0)
            {
                q.push(k->first);
                Vertex_Array[k->first].pid=t;
                Vertex_Array[k->first].dist=Vertex_Array[t].dist+1;
                Vertex_Array[k->first].color=1;
                if(G.directed==0)
                T.addUEdge(t,k->first,k->second);
                else
                T.addEdge(t,k->first,k->second);
                Vertex_Array[k->first].color=1;
            }
        }
    }
    return T;
}   
bool BFS(Graph G,int s,int r)
{
    Vertex Vertex_Array[20]; // To store information about the vertex
    queue <int> q;
    q.push(s);
    Vertex_Array[s].color=1;
    while(!q.empty())
    {
        int t=q.front();
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
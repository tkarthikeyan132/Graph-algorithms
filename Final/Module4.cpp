#include"Module4.h"
using namespace std;
bool Test_bipartite(Graph &G)
{
    queue <int> q;
    Graph T(G.V,0); // bfs tree
    int ce=0,se=0; // cross edges and slant edges
    for(int i=0;i<G.V;i++)
    {
        G.Vertex_Array[i].color=0;
        G.Vertex_Array[i].dist=0;
        G.Vertex_Array[i].pid=-1;
    }
    q.push(0);
    G.Vertex_Array[0].color=1;
    G.Vertex_Array[0].pid=-1; //NULL
    G.Vertex_Array[0].dist=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            int x=k->first;
            if(G.Vertex_Array[x].color==0)
            {
                q.push(x);
                G.Vertex_Array[x].pid=t;
                G.Vertex_Array[x].dist=G.Vertex_Array[t].dist+1;
                G.Vertex_Array[x].color=1;
                T.addUEdge(t,k->first);
                T.E+=2;
            }
        }
    }
    for(int x=0;x<G.V-1;x++)
        for(int y=x+1;y<G.V;y++)
        {
            if(G.checkEdge(x,y)==1&&T.checkEdge(x,y)==0)
            {
                if(G.Vertex_Array[x].dist==G.Vertex_Array[y].dist)
                    ce++;
                else
                    se++;
            }
        }
    if(ce==0)
        return true;
    else
        return false;
}
vector <int> Test_articulationpoints(Graph &G)
{
    queue <int> q;
    Graph T(G.V,G.E);
    vector <int>ap;
    for(int i=0;i<G.V;i++)
    {
        T=G;
        T.adj[i].clear();
        for(int j=0;j<T.V;j++)
        {
            if(i!=j)
            {
                for(auto k=T.adj[j].begin();k<T.adj[j].end();k++)
                {
                    if(k->first==i)
                        T.adj[j].erase(k);
                }
            }
        }
        for(int a=0;a<20;a++)
            G.Vertex_Array[a].color=0;
        int r=((i+1)%(G.V));
        q.push(r); // bfs starts
        G.Vertex_Array[r].color=1;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto k=T.adj[t].begin();k<T.adj[t].end();k++)
            {
                if(G.Vertex_Array[k->first].color==0)
                {
                    q.push(k->first);
                    G.Vertex_Array[k->first].color=1;
                }
            }
        } // bfs ends
        int cou=0;
        for(int u=0;u<G.V;u++)
        {
            if(G.Vertex_Array[u].color==1)
                cou++;
        }
        if(cou!=(G.V-1))
        {
            ap.push_back(i);
        }
    }
    return ap;
}
vector <pair<int,int>> Test_bridges(Graph &G)
{
    queue <int> q;
    Graph T(G.V,G.E); // temporary graph
    int couB=0;
    vector <pair<int,int>> bridge;
    for(int i=0;i<G.V;i++)
    {
        for(auto j=G.adj[i].begin();j<G.adj[i].end();j++)
        {
            int k=j->first;
            T=G;
            for(auto x=T.adj[i].begin();x<T.adj[i].end();x++)
            {
                if(x->first==k)
                    T.adj[i].erase(x);
            }
            for(auto y=T.adj[k].begin();y<T.adj[k].end();y++)
            {
                if(y->first==i)
                    T.adj[k].erase(y);
            }
            for(int a=0;a<20;a++)
                G.Vertex_Array[a].color=0;
            q.push(0); // bfs starts
            G.Vertex_Array[0].color=1;
            while(!q.empty())
            {
                int t=q.front();
                q.pop();
                for(auto k=T.adj[t].begin();k<T.adj[t].end();k++)
                {
                    if(G.Vertex_Array[k->first].color==0)
                    {
                        q.push(k->first);
                        G.Vertex_Array[k->first].color=1;
                    }
                }
            } // bfs ends
            int cou=0;
            for(int u=0;u<G.V;u++)
            {
                if(G.Vertex_Array[u].color==1)
                    cou++;
            }
            if(cou!=G.V)
            {
                bridge.push_back(make_pair(i,k));
                couB++;
            }
        }
    }
    return bridge;
}
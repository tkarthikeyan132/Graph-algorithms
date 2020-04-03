#include"Module4.h"
using namespace std;
bool Test_bipartite(Graph G)
{
    Vertex VertexArray[20];
    queue <int> q;
    Graph T(G.V,0); // bfs tree
    int ce=0,se=0; // cross edges and slant edges
    for(int i=0;i<G.V;i++)
    {
        VertexArray[i].color=0;
        VertexArray[i].dist=0;
        VertexArray[i].pid=-1;
    }
    q.push(0);
    VertexArray[0].color=1;
    VertexArray[0].pid=-1; //NULL
    VertexArray[0].dist=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto k=G.adj[t].begin();k<G.adj[t].end();k++)
        {
            int x=k->first;
            if(VertexArray[x].color==0)
            {
                q.push(x);
                VertexArray[x].pid=t;
                VertexArray[x].dist=VertexArray[t].dist+1;
                VertexArray[x].color=1;
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
                if(VertexArray[x].dist==VertexArray[y].dist)
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
vector <int> Test_articulationpoints(Graph G)
{
    Vertex VertexArray[20];
    queue <int> q;
    Graph T(G.V,G.E);
    vector <int>ap;
    int couAP=0;
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
            VertexArray[a].color=0;
        int r=((i+1)%(G.V));
        q.push(r); // bfs starts
        VertexArray[r].color=1;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto k=T.adj[t].begin();k<T.adj[t].end();k++)
            {
                if(VertexArray[k->first].color==0)
                {
                    q.push(k->first);
                    VertexArray[k->first].color=1;
                }
            }
        } // bfs ends
        int cou=0;
        for(int u=0;u<G.V;u++)
        {
            if(VertexArray[u].color==1)
                cou++;
        }
        if(cou==(G.V-1))
            cout<<i<<" is not an AP"<<endl;
        else
        {
            ap.push_back(i);
            couAP++;
        }
    }
    ap.insert(ap.begin(),couAP);
    return ap;
}
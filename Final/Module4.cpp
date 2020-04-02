#include"Module4.h"
using namespace std;
void level(Graph G,Vertex vertex[],int u,int l);
bool Test_bipartite(Graph G)
{
    int ce=0,se=0;
    Graph T= BFS(G,0);
    Vertex vertex[T.V];
    level(T,vertex,0,0);
    for(int x=0;x<G.V-1;x++)
        for(int y=x+1;y<G.V;y++)
        {
            if(G.checkEdge(x,y) && !(T.checkEdge(x,y)))
            {
                if(vertex[x].dist==vertex[y].color)
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
void level(Graph G,Vertex vertex[],int u,int l)
{
    vertex[u].dist=l;
    vertex[u].color=1;
    for(auto it=G.adj[u].begin();it!=G.adj[u].end();it++)
    {
        if(vertex[it->first].color!=1)
        level(G,vertex,it->first,l+1);
    }
}
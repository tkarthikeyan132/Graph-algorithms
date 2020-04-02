// C++ program to represent undirected and weighted graph 
// using STL. The program basically prints adjacency list 
// representation of graph 
#include"GraphSTL.h"
using namespace std;
void Graph::addEdge(int u, int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
}
void Graph::addUEdge(int u,int v,int wt)
{
    addEdge(u,v,wt);
    addEdge(v,u,wt);
}
void Graph::addUEdge(int u,int v)
{
    addUEdge(u,v,1);
}
void Graph::addEdge(int u,int v)
{
    addEdge(u,v,1);
}
bool Graph::checkEdge(int u,int v)
{
    for(auto it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(it->first==v)
        return true;
    }
    return false;
}
int Graph::delEdge(int u,int v)
{
    int i=0;
    for(auto it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(it->first==v)
        {
            adj[u].erase(it);
            i++;
        }
    }
    if(directed==0)
    {
        for(auto it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(it->first==u)
            {
                adj[v].erase(it);
                i++;
            }
        }
    }
    return i;
}
// Print adjacency list representaion ot graph 
void Graph::printGraph()
{  
    for (int u = 0; u < V; u++) 
    { 
        cout << "Node " << u << " makes an edge with \n"; 
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) 
        {  
            cout << "\tNode " << it->first << " with edge weight ="
                << it->second << endl;   
                /*'it->first' is used becauseiterator 'it' is basically 
                a pointer pointing to the 'it'th pair of 'u'th vector present in the array 'adj' of vectors.*/
        } 
        cout << endl; 
    } 
}
Graph::Graph(int V1,int E1)
{
	V=V1;
	E=E1;
    directed=0;
}
Vertex::Vertex()
{
    color=0;
}
int Comparator(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
}
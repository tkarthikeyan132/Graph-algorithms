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
void Graph::BFS_SPATH_addEdge(int u, int v, int wt, int flag) 
{ 
    if(flag == 0) //unweighted graph
    {
        BFS_SPATH_adj[u].push_back(v); 
    }
    else   //weighted graph
    {
        V_Prime++;
        BFS_SPATH_adj[u].push_back(dummy_vertex);  //creates one dummy_vertex and connects it to u
        for(int i = 1; i <= wt - 2; i++)
        {
            V_Prime++;  //accomodoting space for a new born dummy_vertex.
            BFS_SPATH_adj[dummy_vertex].push_back(dummy_vertex + 1);//creates wt - 1 dummy_vertices and makes wt - 2 edges among consecutive edges.
            dummy_vertex++;
        }
        BFS_SPATH_adj[dummy_vertex].push_back(v); //creates an edge from dummy to v;
        dummy_vertex++;
    }
} 

void Graph::BFS_SPATH_printGraph(int flag) 
{ 
    if(flag == 0)
    {
        for (int u = 0; u < V; u++) 
        { 
            cout << "Node " << u << " connects to nodes\t"; 
            for (auto it = BFS_SPATH_adj[u].begin(); it != BFS_SPATH_adj[u].end(); it++) 
                cout << *it << ", "; 
            cout << endl; 
        } 
    }
    else
    {
        for (int u = 0; u < V; u++) 
        { 
            cout << "Node " << u << " connects to \n"; 
            for ( auto it =  BFS_SPATH_adj[u].begin() ; it != BFS_SPATH_adj[u].end() ; it++) 
            {
                int twt = 0;
                int prev = u;
                int curr = *it;  //curr is a child of u(prev)
                twt++;  //tempweight
                while(curr >= V)
                {
                    if(BFS_SPATH_adj[curr][0] != prev)  // BFS_SPATH_adj[v][0] is a child of v;
                    {
                        prev = curr;
                        curr = BFS_SPATH_adj[curr][0];
                    }
                    else
                    {
                        prev = curr;
                        curr = BFS_SPATH_adj[curr][1];
                    }
                    twt++;
                }
                cout << "\tNode " << curr << " with edge weight ="
                    << twt  << endl << endl;  
            } 
        }
    }
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
            break;
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
                break;
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
Graph::Graph()
{
    directed = 0;
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
void Initialize_for_BFS(Graph &G, int s)
{
    for(int i = 0; i < G.V; i++)
    {
        G.Vertex_Array[i].id = i;
        if(i != s)
        {
            G.Vertex_Array[i].color = 0;
            G.Vertex_Array[i].dist = INFINITY;
            G.Vertex_Array[i].pid = -2;
        }
    }
}

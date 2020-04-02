// C++ program to represent undirected and weighted graph 
// using STL. The program basically prints adjacency list 
// representation of graph 

#include <iostream>
#include <vector> 
using namespace std;
class Edge 
{ 
	public: 
	int src, dest, weight; 
};
int Comparator(const void* a, const void* b);
class Graph
{
	public:
        int V;
        int E;
        int directed;
        vector<pair<int,int>>adj[20]; //makes an array of vectors
        //Adding an edge between vertex u and v.
        void addEdge(int u, int v,int wt)
        {
            adj[u].push_back(make_pair(v,wt));
        }
        void addUEdge(int u,int v,int wt)
        {
            addEdge(u,v,wt);
        }
        void addUEdge(int u,int v)
        {
            addUEdge(u,v,1);
        }
        void addEdge(int u,int v)
        {
            addEdge(u,v,1);
        }
        bool checkEdge(int u,int v)
        {
            for(auto it=adj[u].begin();it!=adj[u].end();it++)
            {
                if(it->first==v)
                return true;
            }
            return false;
        }
        int delEdge(int u,int v)
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
        void printGraph()
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
        Graph(int V1,int E1)
		{
			V=V1;
			E=E1;
            directed=0;
		}
};
struct Vertex
{
    public:
        int id;
        int color;
        int dist;
        int pid;
        int Topological_Number;
        int In_Degree;
};
int Comparator(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
}
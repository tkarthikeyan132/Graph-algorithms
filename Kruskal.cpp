#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
class Edge 
{ 
	public: 
	int src, dest, weight; 
};
// a structure to represent a connected, undirected 
// and weighted graph
class Graph
{
	public:
        int V;
        int E;
        vector<pair<int, int> > adj[200]; //makes an array of vectors

        //Adding an edge between vertex u and v.
        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
            adj[v].push_back(make_pair(u, wt)); 
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
		}
		Graph(const Graph &p2)
		{
			V=p2.V;
			E=p2.E;
            for (int u = 0; u < V; u++) 
            {
                for (auto it = p2.adj[u].begin(); it != p2.adj[u].end(); it++) 
                {
					if(it->first > u)
					addEdge(u,it->first, it->second);
                } 
            }
        }
};
// A structure to represent a subset for union-find 
class sub 
{ 
	public: 
	int pid;
	int level; 
}; 
int find(sub sub_x[], int i) 
{
	if (sub_x[i].pid != i) 
		sub_x[i].pid = find(sub_x, sub_x[i].pid); 

	return sub_x[i].pid; 
} 
void Union(sub sub_x[], int x1, int x2) 
{ 
	int x1root = find(sub_x, x1); 
	int x2root = find(sub_x, x2); 
	if (sub_x[x1root].level < sub_x[x2root].level) 
		sub_x[x1root].pid = x2root; 
	else if (sub_x[x1root].level > sub_x[x2root].level) 
		sub_x[x2root].pid = x1root; 
	else
	{ 
		sub_x[x2root].pid = x1root; 
		sub_x[x1root].level++; 
	}
} 
int Comparator(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 
Graph KruskalMST(Graph graph) 
{ 
	int V = graph.V; 
	Edge result[V];
	int e = 0;
	int i = 0;
	Edge input[graph.E];
	int k=0;
	for (int u = 0; u < V; u++)
    {
    	for (auto it = graph.adj[u].begin(); it != graph.adj[u].end(); it++) 
        {
			if(it->first > u)
			{
				input[k].src=u;
				input[k].dest=it->first;
				input[k].weight=it->second;
				k++;
			}
        }
    }
	qsort(input, graph.E, sizeof(input[0]), Comparator); 
	sub* sub_x = new sub[(V*sizeof(sub))]; 
	for (int v = 0; v < V; ++v) 
	{ 
		sub_x[v].pid=v; 
		sub_x[v].level=0; 
	}
	while (e<V-1 && i<graph.E) 
	{
		Edge next_edge =input[i++]; 
		int x = find(sub_x, next_edge.src); 
		int y = find(sub_x, next_edge.dest);
		if(x!=y)
		{
			result[e++] = next_edge; 
			Union(sub_x,x,y); 
		}
	
	}
	Graph temp(V,e);
	for (i = 0; i < e; ++i) 
	temp.addEdge(result[i].src,result[i].dest,result[i].weight);
	return temp;
}
// Driver code 
int main() 
{ 
	/* Let us create following weighted graph 
		  10 
		0---1 
		|\ 	| 
	   6|5\ |15 
		|  \| 
		2---3 
		  4 */
	int V = 4; // Number of vertices in graph 
	int E = 5; // Number of edges in graph 
	Graph graph(V,E); 
	// add edge 0-1
	graph.addEdge(0,1,10);
	// add edge 0-2
	graph.addEdge(0,2,6);
	// add edge 0-3 
	graph.addEdge(0,3,5);
	// add edge 1-3
	graph.addEdge(1,3,15);
	// add edge 2-3
	graph.addEdge(2,3,4);
	Graph MST = KruskalMST(graph);
	MST.printGraph();
	return 0; 
}
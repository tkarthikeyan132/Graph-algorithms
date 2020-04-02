#include"Module5.h"
using namespace std;
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
Graph MST_Kruskal(Graph graph) 
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
Graph MST_youralgo(Graph graph)
{
    
    Graph temp=BFS(graph,0);
    Edge input[graph.E];
    int k=-1;
    bool flag;
    for (int u = 0; u < graph.V; u++)
    {
    	for (auto it = graph.adj[u].begin(); it != graph.adj[u].end(); it++) 
        {
			if(it->first > u)
			{
                k++;
				input[k].src=u;
				input[k].dest=it->first;
				input[k].weight=it->second;
			}
        }
    }
	qsort(input, graph.E, sizeof(input[0]), Comparator);
    for(int i=0;i<graph.E;i++)
    {
        temp.delEdge(input[i].src,input[i].dest);
        flag=BFS(temp,input[i].src,input[i].dest);
        if(flag==false)
        temp.addEdge(input[i].src,input[i].dest,input[i].weight);
    }
    return temp;
}
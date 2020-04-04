#include"Module5.h"
using namespace std;
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
int minKey(int key[],bool mstSet[],Graph temp)
{
  int min = INT_MAX, min_index;    //Intializing min to infinity
  for (int v = 0; v < temp.V; v++)  
  {
    if (mstSet[v] == false && key[v] < min)      //min_index contains the vertex which has min-key
    min = key[v], min_index = v;  
  }
  return min_index;
}
Graph MST_Prim(Graph G)  
{
  	int parent[G.V];       //MST is stored
  	int key[G.V];         //Min Key Values to maintain Weights
  	bool mstSet[G.V];     //To pair up what are visited
  	Graph temp(G.V,G.V-1);
  	for (int i = 0; i < G.V; i++)  
  	{
    	key[i] = INT_MAX;
    	mstSet[i] = false;
  	}     //All key values are set to infinite and mstSET is made false for all
  	key[0] = 0;                   //Starting with the 1st vertex
  	parent[0] = -1;
  	for (int count = 0;count < G.V;count++)
  	{
    	int u = minKey(key,mstSet,temp);   //Picking the min vertex from the set of vertices not included yet
    	mstSet[u] = true;           //Placing that value
    	if(parent[u]>-1)
    	temp.addUEdge(parent[u],u,key[u]);
    	//Now its important to update the Adjacent vertices of the selected vertex,Should be careful of Already visited vertex
    	for (int v = 0; v < G.V; v++)
    	{
      		int weight;
      		for(auto it=G.adj[u].begin(); it!=G.adj[u].end();it++)
      		{
        	if(it->first==v)
        	weight=it->second;
      		}
      		//The first condition in the "and" checks whether an edge exsits and the second whether the vertex is visited or not
      		// And then we check the weights of the key value and graph value comparing between them
      		if (G.checkEdge(u,v) && !mstSet[v] && weight<key[v])
      		{
        		parent[v] = u;
        		key[v] = weight;
      		}
    	}
  	}
  	return temp;
}
Graph MST_Kruskal(Graph G) 
{
	int V = G.V; 
	Edge result[V];
	int e = 0;
	int i = 0;
	Edge input[G.E];
	int k=0;
	for (int u = 0; u < V; u++)
    {
    	for (auto it = G.adj[u].begin(); it != G.adj[u].end(); it++) 
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
	qsort(input, G.E, sizeof(input[0]), Comparator); 
	sub* sub_x = new sub[(V*sizeof(sub))]; 
	for (int v = 0; v < V; ++v) 
	{ 
		sub_x[v].pid=v; 
		sub_x[v].level=0; 
	}
	while (e<V-1 && i<G.E) 
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
	temp.addUEdge(result[i].src,result[i].dest,result[i].weight);
	return temp;
}
Graph MST_youralgo(Graph G)
{
    
    Graph temp=G;
    Edge input[20];
    int k=-1;
    bool flag;
    for (int u = 0; u < G.V; u++)
    {
    	for (auto it = G.adj[u].begin(); it != G.adj[u].end(); it++) 
        {
			if(it->first > u)
			{
                k++;
				input[k].src=u;
				input[k].dest=it->first;
				input[k].weight=(-1)*it->second;
			}
        }
    }
	qsort(input, G.E, sizeof(input[0]), Comparator);
    for(int i=0;i<G.E;i++)
    {
		Initialize_for_BFS(temp,input[i].src);
        temp.delEdge(input[i].src,input[i].dest);
        flag=BFS(temp,input[i].src,input[i].dest);
        if(!flag)
        temp.addUEdge(input[i].src,input[i].dest,(-1)*input[i].weight);
    }
    return temp;
}
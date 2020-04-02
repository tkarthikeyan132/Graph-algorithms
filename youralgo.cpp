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
            for(auto it=adj[v].begin();it!=adj[v].end();it++)
            {
                if(it->first==u)
                {
                    adj[v].erase(it);
                    i++;
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
int Comparator(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
}
bool BFS(Graph G,int s,int r)
{
    queue <int> q;
    q.push(s);
    int visit[G.V]={0};
    visit[s]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto k=G.adj[t].begin();k!=G.adj[t].end();k++)
        {
            if(visit[k->first]==0)
            {
                q.push(k->first);
                visit[k->first]=1;
            }
        }
    }
    if(visit[r]==1)
    return true;
    else
    return false;
}
Graph BFS(Graph G, int s)
{
    Graph T(G.V,0);
    int e=0;
    queue <int> q;
    q.push(s);
    int visit[G.V];
    visit[s]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto k=G.adj[t].begin();k!=G.adj[t].end();k++)
        {
            int x=k->first;
            if(visit[x]==0)
            {
                e++;
                q.push(x);
                visit[x]=1;
                if(!(T.checkEdge(x,t)))
                T.addEdge(x,t,k->second);
            }
        }
    }
    T.E=e;
    return T;
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
//driver
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
	Graph MST = MST_youralgo(graph);
	MST.printGraph();
	return 0; 
}
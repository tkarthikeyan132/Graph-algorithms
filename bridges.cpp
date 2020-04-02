#include <iostream>
#include <bits/stdc++.h> 
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
            addEdge(v,u,wt);
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
Vertex VertexArray[20];
bool Test_bridges(Graph G);
queue <int> q;
int main()
{
    int N,M;
    cout<<"Enter the number of vertices:";
    cin>>N;
    cout<<"Vertices are:";
    for(int u=0;u<N;u++)
        cout<<u<<" ";
    cout<<"\nEnter the number of edges:";
    cin>>M;
    Graph G(N,M);
    for(int l=0;l<G.E;l++)
    {
        int x,y;
        cin>>x>>y;
        G.addUEdge(x,y);
    }
    if(Test_bridges(G))
        cout<<"Graph contains bridges"<<endl;
    else
        cout<<"Graph is free of bridges"<<endl; 
    return 0;
}
bool Test_bridges(Graph G)
{
    Graph T(G.V,G.E); // temporary graph
    int couB=0;
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
                VertexArray[a].color=0;
            q.push(0); // bfs starts
            VertexArray[0].color=1;
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
            if(cou==G.V)
                cout<<"("<<i<<","<<k<<")"<<" is not a bridge"<<endl;
            else
            {
                cout<<"("<<i<<","<<k<<")"<<" is a bridge"<<endl;
                couB++;
            }
        }
    }
    if(couB)
        return true;
    else
        return false;
}
    

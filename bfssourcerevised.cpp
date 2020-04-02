#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
Vertex Vertex_Array[20];
class Graph
{
    public:
    int V;
    int E;
    vector <int> adj[20];
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printGraph()
    {
        for(int u=0;u<V;u++)
        {
            cout<<"Vertex "<<u<<":";
            for(int v=0;v!=adj[u].size();v++)
                cout<<adj[u][v]<<" ";
            cout<<endl;
        }
    }
};
Graph BFS(Graph G,int s);
queue <int> q;
int main()
{
    Graph G;
    int s;
    cout<<"Enter the number of vertices:";
    cin>>G.V;
    cout<<"Vertices are:";
    for(int u=0;u<G.V;u++)
        cout<<u<<" ";
    cout<<"\nEnter the number of edges:";
    cin>>G.E;
    for(int l=0;l<G.E;l++)
    {
        int x,y;
        cin>>x>>y;
        G.addEdge(x,y);
    }
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"BFS result:"<<endl;
    Graph T=BFS(G,s); // T is bfs tree
    cout<<endl;
    return 0;
}
Graph BFS(Graph G, int s)
{
    Graph T;
    T.V=G.V;
    q.push(s);
    Vertex_Array[s].color=1;
    Vertex_Array[s].pid=-1; //NULL
    Vertex_Array[s].dist=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(int k=0;k<G.adj[t].size();k++)
        {
            int x=G.adj[t][k];
            if(Vertex_Array[x].color==0)
            {
                q.push(x);
                Vertex_Array[x].pid=t;
                Vertex_Array[x].dist=Vertex_Array[t].dist+1;
                Vertex_Array[x].color=1;
                T.adj[t].push_back(x);
                T.adj[x].push_back(t);
            }
        }
    }
    return T;
}

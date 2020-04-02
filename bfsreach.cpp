#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
bool BFS(Graph G,int s,int r);
int visit[20]={0};
queue <int> q;
int main()
{
    Graph G;
    int s,r;
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
    cout<<"Enter the vertex where you want to reach:";
    cin>>r;
    cout<<"BFS result:"<<endl;
    if(BFS(G,s,r))
        cout<<"reachable";
    else
        cout<<"not reachable";
    cout<<endl;
    return 0;
}
bool BFS(Graph G,int s,int r)
{
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(t==r)
            return true;
        for(int k=0;k<G.adj[t].size();k++)
        {
            if(visit[G.adj[t][k]]==0)
            {
                q.push(G.adj[t][k]);
                visit[G.adj[t][k]]=1;
            }
        }
    }
    return false;
}
        

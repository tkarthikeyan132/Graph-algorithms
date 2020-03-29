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
void DFS(Graph G,int s);
int visit[20]={0};
stack <int> q;
int main()
{
    Graph G;
    int s;
    cout<<"Enter the number of vertices:";
    cin>>G.V;
    cout<<"Vertices are:";
    for(int y=0;y<G.V;y++)
        cout<<y<<" ";
    cout<<"\nEnter the number of edges:";
    cin>>G.E;
    for(int u=0;u<G.E;u++)
    {
        int x,y;
        cin>>x>>y;
        G.addEdge(x,y);
    }
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"DFS result:";
    DFS(G,s);
    cout<<endl;
    return 0;
}
void DFS(Graph G,int s)
{
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        cout<<t<<" ";
        for(int k=0;k<G.adj[t].size();k++)
        {
            if(visit[G.adj[t][k]]==0)
            {
                q.push(G.adj[t][k]);
                visit[G.adj[t][k]]=1;
            }
        }
    }
}

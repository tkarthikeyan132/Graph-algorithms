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
void BFS(Graph G,int s);
bool Test_bridges(Graph G);
int visit[20]={0};
queue <int> q;
Graph T; // temporary graph
int main()
{
    Graph G;
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
    if(Test_bridges(G))
        cout<<"Graph contains bridges"<<endl;
    else
        cout<<"Graph is free of bridges"<<endl; 
    return 0;
}
void BFS(Graph G,int s)
{
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
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
bool Test_bridges(Graph G)
{
    int couB=0;
    for(int i=0;i<G.V;i++)
    {
        for(int j=0;j<G.adj[i].size();j++)
        {
            int k=G.adj[i][j];
            T=G;
            for(int x=0;x<T.adj[i].size();x++)
            {
                if(T.adj[i][x]==k)
                    T.adj[i].erase(T.adj[i].begin()+x);
            }
            for(int y=0;y<T.adj[k].size();y++)
            {
                if(T.adj[k][y]==i)
                    T.adj[k].erase(T.adj[k].begin()+y);
            }
            for(int a=0;a<20;a++)
            visit[a]=0;
            BFS(T,0);
            int cou=0;
            for(int u=0;u<G.V;u++)
            {
                if(visit[u]==1)
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
    

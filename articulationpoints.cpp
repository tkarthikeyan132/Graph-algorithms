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
bool Test_articulationpoints(Graph G);
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
    if(Test_articulationpoints(G))
        cout<<"Graph contains articulation points"<<endl;
    else
        cout<<"Graph is free of articulation points"<<endl;
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
bool Test_articulationpoints(Graph G)
{
    int couAP=0;
    for(int i=0;i<G.V;i++)
    {
        T=G;
        T.adj[i].clear();
        for(int j=0;j<T.V;j++)
        {
            if(i!=j)
            {
                for(int k=0;k<T.adj[j].size();k++)
                {
                    if(T.adj[j][k]==i)
                        T.adj[j].erase(T.adj[j].begin()+k);
                }
            }
        }
        for(int a=0;a<20;a++)
            visit[a]=0;
        int r=((i+1)%(G.V));
        BFS(T,r);
        int cou=0;
        for(int u=0;u<G.V;u++)
        {
            if(visit[u]==1)
                cou++;
        }
        if(cou==(G.V-1))
            cout<<i<<" is not an AP"<<endl;
        else
        {
            cout<<i<<" is an AP"<<endl;
            couAP++;
        }
    }
    if(couAP)
        return true;
    else
        return false;
}
    

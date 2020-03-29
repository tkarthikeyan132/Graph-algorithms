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
bool searchedge(vector <int> bdj[20],int u,int v);
bool Test_bipartite(Graph G);
void BFS(Graph G);
int visit[20]={0};
int level[20]={0};
int parent[20];
int ce=0,se=0;
vector < int > tadj[20];
queue <int> q;
int main()
{
    Graph G;
    for(int w=0;w<20;w++)
    parent[w]=-1;
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
    if(Test_bipartite(G))
        cout<<"Graph is bipartite"<<endl;
    else
        cout<<"Graph is not bipartite"<<endl;
    return 0;
}
void BFS(Graph G)
{
    q.push(0);
    visit[0]=1;
    parent[0]=-1; //NULL
    level[0]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int k=0;k<G.adj[t].size();k++)
        {
            int x=G.adj[t][k];
            if(visit[x]==0)
            {
                q.push(x);
                parent[x]=t;
                level[x]=level[t]+1;
                visit[x]=1;
                tadj[t].push_back(x);
                tadj[x].push_back(t);
            }
        }
    }
}
bool searchedge(vector <int> bdj[20],int u,int v)
{
    for(int i=0;i<bdj[u].size();i++)
    {
        if(bdj[u][i]==v)
            return true;
    }
    return false;
}
bool Test_bipartite(Graph G)
{
    BFS(G);
    for(int x=0;x<G.V-1;x++)
        for(int y=x+1;y<G.V;y++)
        {
            if(searchedge(G.adj,x,y)==1&&searchedge(tadj,x,y)==0)
            {
                if(level[x]==level[y])
                    ce++;
                else
                    se++;
            }
        }
    if(ce==0)
        return true;
    else
        return false;
}
    

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


vector<int> LPATH(Graph T);
void Initialize_for_BFS(Graph G, int s);
Graph BFS(Graph G,int s);

queue <int> q;
int main()
{
    Graph G;
    Graph T;
    int s;  
    vector<int> lpath(G.V + 1);
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
    lpath = LPATH(G);
    cout << "The length of the lpath is :" << lpath[0] << endl;
    for(auto it = lpath.begin() + 1; it != lpath.end(); it++)
        cout << "(" << *it << ")<--";
    cout << endl;
    return 0;
}

vector<int> LPATH(Graph T) //an unweighted tree.
{
    int max_dist = 0;
    vector<int> Final_vector(T.V + 1);
    int deepest_node_id = 0;     //first_end_of_lpath_id
    int second_end_of_lpath_id = 0;
    Initialize_for_BFS(T, 0);
    T = BFS(T, 0); // T is bfs tree
    for(int i = 0; i < T.V; i++)
    {
        if(max_dist < Vertex_Array[i].dist)
        {
            max_dist = Vertex_Array[i].dist;
            deepest_node_id = i;
        }
    }
    max_dist = 0;
    Initialize_for_BFS(T, deepest_node_id);
    BFS(T, deepest_node_id);
    for(int i = 0; i < T.V; i++)
    {
        if(max_dist < Vertex_Array[i].dist)
        {
            max_dist = Vertex_Array[i].dist;
            second_end_of_lpath_id = i;
        }
    }
    int i = second_end_of_lpath_id;
    int j = 1; 
    while(Vertex_Array[i].id != deepest_node_id)
    {
        Final_vector[j] = i;
        i = Vertex_Array[i].pid;
        j++;
    }
    Final_vector[0] = j - 1;
    Final_vector[j] = i;
    Final_vector.resize(j + 1);
    return Final_vector ;
}

void Initialize_for_BFS(Graph G, int s)
{
    for(int i = 0; i < G.V; i++)
    {
        Vertex_Array[i].id = i;
        if(i != s)
        {
            Vertex_Array[i].color = 0;
            Vertex_Array[i].dist = INFINITY;
            Vertex_Array[i].pid = -2;
        }
    }
}


    
Graph BFS(Graph G, int s)
{
    Graph T;
    T.V=G.V;
    q.push(s);
    Vertex_Array[s].color=1;
    Vertex_Array[s].pid=G.V; //NULL
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
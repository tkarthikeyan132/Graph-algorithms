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
};
Vertex Vertex_Array[20];
void Initialize_single_source(Graph G, Vertex s);
vector<int> topological_ordering(Graph G);
int main()
{
    Graph G;
    int x,y;
    vector<int> Topological_Vector(G.V); 
    cout<<"Enter the number of vertices:";
    cin>>G.V;
    cout<<"Enter the number of edges:";
    cin>>G.E;
    for(int i = 0; i < G.V; i++)
        Vertex_Array[i].In_Degree = 0;  //instead of making a constructor, I did this.
    for(int w=0;w<G.E;w++)
    {
        cin>>x>>y;
        G.addEdge(x,y);
        Vertex_Array[y].In_Degree++;
    }
    Topological_Vector = topological_ordering(G);
    for(int i=0;i<G.V;i++)
        cout<<Topological_Vector[i]<<" ";
    return 0;
}


vector<int> LPATH(Graph G)
{
    int count;
    vector<int> Zero_In_degree(200); //vector
    vector<int> Topological_Vector(G.V);
    Topological_Vector = topological_ordering(G);
    for(int i = 0; i < G.V; i++)
    {
        if(Vertex_Array[i].In_Degree == 0)
        {
            Zero_In_degree.push_back(i);
            count++;
        }
    }
    Zero_In_degree.resize(count);
    vector<int> LPATH_Vector[count]; //vector array
    for(int i = 0; i < count; i++)
    {
        LPATH_Vector[i].resize(G.V);

    
    

}

vector<int> topological_ordering(Graph G)
{
    queue <int> q;
    vector<int> Topological_Vector(G.V);
    int counter = 0;
    for(int i = 0; i < G.V; i++)
    {
        if(Vertex_Array[i].In_Degree == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        Vertex_Array[y].Topological_Number = counter;
        Topological_Vector[counter] = y;
        counter++;
        for(int j = 0; j < G.adj[y].size(); j++)
        {
            Vertex_Array[G.adj[y][j]].In_Degree--;
            if(Vertex_Array[G.adj[y][j]].In_Degree == 0)
                q.push(G.adj[y][j]);
        }
    }
    if(counter != G.V)
        cout << "cycle found !!" << endl;
    return Topological_Vector;
}


vector<int> DAG_LONGEST_PATH(Graph G, Vertex s)
{
    
    Initialize_single_source(G, s);
    for(int i = 0; i < G.V; i++)
    {



} 


void Initialize_single_source(Graph G, Vertex s)
{

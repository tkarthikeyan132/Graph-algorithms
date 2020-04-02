#include<bits/stdc++.h>
using namespace std;
struct Vertex
{
    public:
        int id;     //vertex id
        int color;
        int dist;
        int pid;   //parent id
        int child;  //child id
        int Topological_Number;
        int In_Degree;
};
class Graph
{
    public:
    int V;
    int E;
    vector<pair<int, int>> adj[20];
    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
    }
};


vector<int> LPATH(Graph G);
vector<int> topological_ordering(Graph G);
vector<int> DAG_LONGEST_PATH(Graph G, Vertex s, vector<int> Topological_vector);
void Initialize_single_source(Graph G, Vertex s);
void RELAX(int uid, vector<pair<int, int>>::iterator it);

int Zero_In_degree = 0;
Vertex Vertex_Array[20];

int main()
{
    Graph G;
    int x, y, wt;
    vector<int> lpath; 
    cout << "Enter the number of vertices:";
    cin >> G.V;
    cout << "Enter the number of edges:";
    cin >> G.E;
    for(int i = 0; i < G.V; i++)
    {
        Vertex_Array[i].In_Degree = 0;  //instead of making a constructor, I did this.
        Vertex_Array[i].id = i;
    }
    for(int w = 0; w < G.E; w++)
    {
        cin >> x >> y >> wt;
        G.addEdge(x, y, wt);
        Vertex_Array[y].In_Degree++;
    }
    
    lpath = LPATH(G);

    for(auto it = lpath.begin(); it != lpath.end(); it++)
        cout << *it << "--->";
    return 0;
}


vector<int> LPATH(Graph G)
{
    int MAX = 0;
    vector<int> Topological_Vector(G.V);
    vector<int> Final_Vector(G.V);
    /*for(int i = 0; i < G.V; i++)
    {
        for(auto it = G.adj[i].begin(); it != G.adj[i].end(); it++)
        {
            it->second = (-1) * it->second; //negating the weights.
        }
    } */
    Topological_Vector = topological_ordering(G); //determines the Zero_In_degree.
    vector<int> LPATH_Vector[Zero_In_degree]; //vector array
    for(int i = 0; i < Zero_In_degree; i++)
    {
        LPATH_Vector[i].resize(G.V);
        LPATH_Vector[i] = DAG_LONGEST_PATH(G, Vertex_Array[Topological_Vector[i]], Topological_Vector);
        if(LPATH_Vector[i][0] > MAX)
        {
            MAX = LPATH_Vector[i][0];
            Final_Vector = LPATH_Vector[i];
        }
    }
    return Final_Vector;
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
    Zero_In_degree = q.size();    //used to mark where the cluster of zero in degree vertices ends in the Topological_Vector.
    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        Vertex_Array[y].Topological_Number = counter;
        Topological_Vector[counter] = y;
        counter++;
        for(auto it = G.adj[y].begin(); it != G.adj[y].end(); it++)//for(int j = 0; j < G.adj[y].size(); j++)
        {
            Vertex_Array[it->first].In_Degree--;
            if(Vertex_Array[it->first].In_Degree == 0)
                q.push(it->first);
        }
    }
    if(counter != G.V)
        cout << "cycle found !!" << endl;
    return Topological_Vector;
}


vector<int> DAG_LONGEST_PATH(Graph G, Vertex s, vector<int> Topological_vector)
{
    vector<int> LPATH(G.V);
    int length = 0;
    Initialize_single_source(G, s);
    for(int i = 0; i < G.V; i++)
    {
        for(auto it = G.adj[ Topological_vector[i]].begin(); it != G.adj[ Topological_vector[i]].end(); it++)
        {
            RELAX(Topological_vector[i], it);
        }
    }
    int i = s.id;   //the path starts from source s;
    int j = 1; 
    while(Vertex_Array[i].child != -2)
    {
        LPATH[j] = i;
        //length = max(length, Vertex_Array[i].dist);
        i = Vertex_Array[i].child;
        j++;
    }
    LPATH[j] = i;
    LPATH[0] = Vertex_Array[i].dist;
    return LPATH;
} 


void Initialize_single_source(Graph G, Vertex s)
{
    for(int i = 0; i < G.V; i++)
    {

        Vertex_Array[i].child = -2;
        if(i != s.id)
            Vertex_Array[i].dist = (-1) * INFINITY;
        else
            Vertex_Array[i].dist = 0;     
        
    }
}

/*
void RELAX(Vertex u, Vertex v)
{
    if(v.dist > u.dist + 1)
    {
        v.dist = u.dist + 1;
        u.child = v.id;  // equivalent to doing v.pid = u.id
    }
}*/

void RELAX(int uid, vector<pair<int, int>>::iterator it)
{
    if(Vertex_Array[it->first].dist < Vertex_Array[uid].dist + it->second)
    {                           //it->second corresponds to the weight of edge (u)---->(it->first)
        Vertex_Array[it->first].dist = Vertex_Array[uid].dist + it->second; 
        Vertex_Array[uid].child = it->first;
    }
}
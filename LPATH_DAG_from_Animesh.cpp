//Finding the longest path in a DAG by negating the weights and use the same subroutine as DAG shortest path given in CLRS.
#include<bits/stdc++.h>
using namespace std;
struct Vertex
{
    public:
        int id;     //vertex id
        int color;
        int dist;
        int pid;   //parent id
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

int Zero_In_degree = 0;
Vertex Vertex_Array[20];

int main()
{
    Graph G;
    int x, y, wt;
    vector<int> lpath(G.V + 1); 
    cout << "Enter the number of vertices:";
    cin >> G.V;
    cout << "Enter the number of edges:";
    cin >> G.E;
    for(int i = 0; i < G.V; i++)
    {
        Vertex_Array[i].In_Degree = 0; 
        Vertex_Array[i].id = i;
    }
    for(int w = 0; w < G.E; w++)
    {
        cin >> x >> y >> wt;
        G.addEdge(x, y, wt);
        Vertex_Array[y].In_Degree++;
    }
    lpath = LPATH(G);
    cout << "The length of the lpath is :" << lpath[0] << endl;
    for(auto it = lpath.begin() + 1; it != lpath.end(); it++)
        cout << "(" << *it << ")<--";
    cout << endl;  
    return 0;
}


vector<int> LPATH(Graph G)
{
    int MAX = 0;
    int source_of_lpath = 0;
    vector<int> Topological_Vector(G.V);
    vector<int> Final_Vector(G.V + 1);
    for(int i = 0; i < G.V; i++)
    {
        for(auto it = G.adj[i].begin(); it != G.adj[i].end(); it++)
        {
            it->second = (-1) * it->second; //negating the weights.
        }
    } 
    Topological_Vector = topological_ordering(G); //determines the Zero_In_degree.
    vector<int> LPATH_Vector[Zero_In_degree]; //vector array
    for(int i = 0; i < Zero_In_degree; i++)
    {
        LPATH_Vector[i].resize(G.V + 1);
        LPATH_Vector[i] = DAG_LONGEST_PATH(G, Vertex_Array[Topological_Vector[i]], Topological_Vector);
        if(LPATH_Vector[i][0] < MAX)
        {
            MAX = LPATH_Vector[i][0];
            Final_Vector = LPATH_Vector[i];
            source_of_lpath = Topological_Vector[i];
        }
    }
//__________work is done till now, the structure of the vector is now arranged to return in a proper way.
    Final_Vector[0] = (-1) * Final_Vector[0];   //making the length of the longest path positive.
    for(int i = 1; i < G.V + 1; i++)
    {
        if(Final_Vector[i] == source_of_lpath)
        {
            Final_Vector.resize(i + 1);
            break;
        }
    }
    return Final_Vector; //remember the first element contains the longest path.
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
        for(auto it = G.adj[y].begin(); it != G.adj[y].end(); it++)
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
    vector<int> LPATH(G.V + 1);
    int Max_length = 0;
    int Max_leaf = 0;
    for(int i = 0; i < G.V; i++) //Initialize single source
    {
        if(i != s.id)
        {
            Vertex_Array[i].dist = INFINITY;
            Vertex_Array[i].pid = -2;
        }
        else
        {
            Vertex_Array[i].dist = 0;
            Vertex_Array[i].pid = G.V;
        }     
    }
    for(int i = 0; i < G.V; i++) //RELAX every edge emerging from Topological_vector[i]
    {
        int u = Topological_vector[i];  //accessing the vertices in the toplogical manner.
        for(auto it = G.adj[u].begin(); it != G.adj[u].end(); it++)
        {
            if(Vertex_Array[it->first].dist > Vertex_Array[u].dist + it->second)
            {                //it->second corresponds to the weight of edge (u)---->(it->first)
                Vertex_Array[it->first].dist = Vertex_Array[u].dist + it->second; 
                Vertex_Array[it->first].pid = u;
            }
        }
    }

    for(int i = 0; i < G.V; i++)
    {
        if(Vertex_Array[i].dist < Max_length) //all weights are negative thus used '<' symbol.
        {
            Max_length = Vertex_Array[i].dist;  //our Max_length is actually Min_length.
            Max_leaf = i;   //Max_lenght is basically negated Maximum length of the path.
        }
    }

    LPATH[0] = Vertex_Array[Max_leaf].dist;
    int i = Max_leaf;
    int j = 1; 
    while(Vertex_Array[i].pid != G.V)
    {
        LPATH[j] = i;
        i = Vertex_Array[i].pid;
        j++;
    }
    LPATH[j] = i;
    return LPATH;
} 




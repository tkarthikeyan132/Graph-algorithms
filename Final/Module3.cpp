#include"Module3.h"
using namespace std;
void Initialize_for_BFS(Graph G, int s,Vertex Vertex_Array[])
{
    Vertex_Array[s].id = s;
    Vertex_Array[s].color = 1;
    for(auto it = G.adj[s].begin(); it!=G.adj[s].end(); it++)
    {
        if(Vertex_Array[it->first].color!=1)
        {
            Vertex_Array[it->first].pid=s;
            Vertex_Array[it->first].dist=Vertex_Array[s].dist+1;
            Initialize_for_BFS(G,it->first,Vertex_Array);
        }
    }
}
vector<int> LPATH(Graph T) //an unweighted tree.
{
    Vertex Vertex_Array[T.V];
    queue <int> q;
    int max_dist = 0;
    vector<int> Final_vector(T.V + 1);
    int deepest_node_id = 0;     //first_end_of_lpath_id
    int second_end_of_lpath_id = 0;
    T = BFS(T,0); // T is bfs tree
    for (int i=0;i<T.V; i++)
    Vertex_Array[i].color=0;
    Vertex_Array[0].color=1;
    Initialize_for_BFS(T,0,Vertex_Array);
    for(int i = 0; i < T.V; i++)
    {
        if(max_dist < Vertex_Array[i].dist)
        {
            max_dist = Vertex_Array[i].dist;
            deepest_node_id = i;
        }
    }
    max_dist = 0;
    BFS(T, deepest_node_id);
    for (int i=0;i<T.V; i++)
    Vertex_Array[i].color=0;
    Vertex_Array[0].color=1;
    Initialize_for_BFS(T, deepest_node_id);
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
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int Comparator(const void* a, const void* b);
class Edge 
{ 
	public: 
	int src, dest, weight; 
};
class Vertex
{
    public:
        int id;
        int color;
        int dist;
        int pid;
        int Topological_Number;
        int In_Degree;
        Vertex();
};
class Graph
{
	public:
        int V;
        int E;
	int  V_Prime; //for SPATH Algorithms
        int dummy_vertex; //for SPATH Algorithms
        int directed;
        vector<pair<int,int>>adj[200]; //makes an array of vectors(adjancency list)
	vector<int> BFS_SPATH_adj[200];  //Special adjacency list for SPATH algorithms. 
        Vertex Vertex_Array[200];
        //Adding an edge between vertex u and v.
        void addEdge(int u, int v,int wt);
        void addUEdge(int u,int v,int wt);
        void addUEdge(int u,int v);
        void addEdge(int u,int v);
        bool checkEdge(int u,int v);
        int delEdge(int u,int v);
	void BFS_SPATH_addEdge(int u, int v, int wt, int flag);
        void BFS_SPATH_printGraph(int flag); 
        // Print adjacency list representaion ot graph 
        void printGraph();
        Graph(int V1,int E1);
        Graph();
};
void Initialize_for_BFS(Graph &G, int s);

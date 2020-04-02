#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
class Edge 
{ 
	public: 
	int src, dest, weight; 
};
class Graph
{
	public:
        int V;
        int E;
        int directed;
        vector<pair<int,int>>adj[20]; //makes an array of vectors
        //Adding an edge between vertex u and v.
        void addEdge(int u, int v,int wt);
        void addUEdge(int u,int v,int wt);
        void addUEdge(int u,int v);
        void addEdge(int u,int v);
        bool checkEdge(int u,int v);
        int delEdge(int u,int v);
        // Print adjacency list representaion ot graph 
        void printGraph();
        Graph(int V1,int E1);
};
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
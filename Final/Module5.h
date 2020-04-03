#include"Module1.h"
using namespace std;
// A structure to represent a subset for union-find 
class sub
{ 
	public: 
	int pid;
	int level; 
};
int find(sub sub_x[], int i);
void Union(sub sub_x[], int x1, int x2);
int minKey(int key[],bool mstSet[],Graph temp);
Graph MST_Prim(Graph G);
Graph MST_Kruskal(Graph G);
Graph MST_youralgo(Graph G);
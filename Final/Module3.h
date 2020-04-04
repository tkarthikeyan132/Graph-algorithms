#include"Module1.h"
using namespace std;
int Zero_In_degree = 0;
void Initialize_for_BFS(Graph G, int s);
vector<int> topological_ordering(Graph G);
vector<int> DAG_LONGEST_PATH(Graph G, Vertex s, vector<int> Topological_vector);
vector<int> LPATH(Graph T,int flag);
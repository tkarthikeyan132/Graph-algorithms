#include"Module1.h"
using namespace std;

vector<int> LPATH(Graph &G, int flag);
vector<int> topological_ordering(Graph &G);
vector<int> DAG_LONGEST_PATH(Graph &G, Vertex s, vector<int> Topological_vector);
vector<vector<int>> BFS_SPATH(Graph G, Vertex s, int flag);

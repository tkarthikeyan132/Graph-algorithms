#include"Module5.h"
using namespace std;

vector<int> LPATH(Graph &G, int flag);
vector<int> topological_ordering(Graph &G);
vector<int> DAG_LONGEST_PATH(Graph &G, Vertex s, vector<int> Topological_vector);
vector<vector<int>> BFS_SPATH(Graph G, Vertex s, int flag);
Graph MAX_Weight_MST(Graph G);   //a part of module5 is done here and it has a purpose.

#include"Module1.h"
using namespace std;

vector<int> LPATH(Graph &G, int flag);
void Initialize_for_BFS(Graph &G, int s);
vector<int> topological_ordering(Graph &G);
vector<int> DAG_LONGEST_PATH(Graph &G, Vertex s, vector<int> Topological_vector);

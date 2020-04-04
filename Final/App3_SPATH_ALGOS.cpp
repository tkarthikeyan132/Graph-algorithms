#include"Module3.h"

int main() 
{ 
	Graph G;
    Vertex s;
    int x, y, wt=1, flag;
    printf("Enter the no of nodes in the Graph: ");
    cin >> G.V;
    G.V_Prime = G.V;
    G.dummy_vertex = G.V;
    printf("Enter the no of edges in the Graph: ");
    cin >> G.E;
    cout << "Enter 1 if the graph is weighted, else 0 ";
    cin >> flag;
    vector<vector<int>> Output_Vector(G.V_Prime);
    for(int i = 0; i < G.E; i++)
    {
        if(flag == 0)
        {
            cin >> x >> y;
            G.BFS_SPATH_addEdge(x, y, wt, flag);
        }
        else
        {
            cin >> x >> y >> wt;
            G.BFS_SPATH_addEdge(x, y, wt, flag);
        }
    }
    cout << "\nGraph:" << endl;
	G.BFS_SPATH_printGraph(flag); 
    printf("Enter BFS source vertex from which spath will be calculated: ");
    cin >> s.id;
    Output_Vector = BFS_SPATH(G, s, flag);
    if(flag == 0)
    {
        for(int i = 0; i < G.V; i++)
        {
            cout << "spath of " << i << ": ";
            for(int j = 0; j < G.V && Output_Vector[i][j] != -1 ; j++)
                cout << "<----(" << Output_Vector[i][j] << ")";
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < G.V; i++)
        {
            cout << "spath of " << i << "from" << s.id << ": ";
            for(int j = 0; j < G.V_Prime && Output_Vector[i][j] != -1 ; j++)
                cout << "<----(" << Output_Vector[i][j] << ")";
            cout << endl;
        }
    }
    cout << "Spath -2 denotes the spath of source itself,that is meaningless \n";
    return 0; 
}
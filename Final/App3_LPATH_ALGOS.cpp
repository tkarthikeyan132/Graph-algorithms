#include"Module3.h"



int main()
{
    Graph G;
    int x, y, wt, flag, tick;
    vector<int> lpath(G.V + 1);
    cout << "Enter the number of vertices:";
    cin >> G.V;
    cout << "Vertices are:";
    for (int i = 0; i < G.V; i++)
    {
        G.Vertex_Array[i].In_Degree = 0;
        G.Vertex_Array[i].id = i;
        cout << i << " ";
    }
    cout << "\nEnter the number of edges:";
    cin >> G.E;
    cout << "Enter 1 if the tree is DAG, and 0 if a normal tree: ";
    cin >> flag;
    for (int l = 0; l < G.E; l++)
    {
        if (flag == 0)
        {
            cin >> x >> y;
            G.addUEdge(x, y); //undirected unweighted edge
        }
        else
        {
            cin >> x >> y >> wt;
            G.addEdge(x, y, wt); //directed weighted edge
            G.Vertex_Array[y].In_Degree++;
        }
    }
    cout << "Enter 0 for finding lpath and 1 for finding MST" << endl;
    cin >> tick;
    if(tick == 0)
    {
        lpath = LPATH(G, flag);
        cout << "The length of the lpath is :" << lpath[0] << endl;
        cout << "The lpath is: " << endl;
        for (auto it = lpath.begin() + 1; it != lpath.end(); it++)
            cout << "(" << *it << ")<--";
        cout << endl;
    }
    else
    {
        Graph MST;
        MST.V = G.V;
        MST.E = G.E;
        MST = MAX_Weight_MST(G);
        cout << "The max weight MST is:" << endl;
        MST.printGraph();
        cout << endl;
    }
    return 0;
}

#include"Module5.h"
int main()
{
    int N,M; // N is no of vertices and M is no of edges
    int x,y,z,d; // dummy variables
    int swh; // switch operation
    cout << "Enter 0 for unweighted graph and 1 for weighted graph:";
    cin >> d;
    cout << "Enter the number of vertices in the graph:";
    cin >> N;
    cout << "Vertices are:";
    for(int i=0;i<N;i++)
        cout << i <<" ";
    cout << "\nEnter the number of edges in the graph:";
    cin >> M;
    Graph G(N,M);
    if(d==0)
    {
        for(int j=0;j<M;j++)
        {
            cin >> x >> y;
            G.addUEdge(x,y);
        }
    }
    else
    {
        for(int j=0;j<M;j++)
        {
            cin >> x >> y >> z;
            G.addUEdge(x,y,z);
        }
    }
    while(true)
    {
        cout << "Operations:\n1.Prim: it will return a MST\n2.Kruskal: it will return a MST\n3.YourAlgo: it will return a MST\n4.Exit\nEnter your choice:";
        cin >> swh;
        Graph M(G.V,G.V-1);
        switch( swh )
        {
            case 1: {
                        M = MST_Prim(G);
                        M.printGraph();
                        cout << endl;
                        break;
                    }
            case 2: {
                        M = MST_Kruskal(G);
                        M.printGraph();
                        cout << endl;
                        break;
                    }
            case 3: {
                        M = MST_youralgo(G);
                        M.printGraph();
                        cout << endl;
                        break;
                    }
            case 4: exit(0);
            default: cout<<"Invalid operation !!"<< endl;
        }
        cout << endl;
    }
    return 0;
}

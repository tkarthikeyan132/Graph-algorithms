#include"Module2.h"
int main()
{
    int N,M; // N is no of vertices and M is no of edges
    int x,y,d; // dummy variables
    int swh; // switch operation
    cout << "Enter 0 for undirected graph and 1 for directed graph:";
    cin >> d;
    cout << "Enter the number of vertices in the graph:";
    cin >> N;
    cout << "Vertices are:";
    for(int i=0;i<N;i++)
        cout << i <<" ";
    cout << "\nEnter the number of edges in the graph:";
    cin >> M;
    Graph G(N,M);
    G.directed = d;
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
            cin >> x >> y;
            G.addEdge(x,y);
        }
    }
    while(true)
    {
        cout << "Operations:\n1.DFS(0 as source vertex): It will print in the order of traversal\n2.DFS(s as source vertex): It will return a DFS tree\n3.DFS(s as source vertex and r as reaching point): It will return whether r can be reached from s or not\n4.Exit\nEnter your choice:";
        cin >> swh;
        switch( swh )
        {
            case 1: {
                        Initialize_for_BFS(G,0);
                        DFS(G);
                        cout << endl;
                        break;
                    }
            case 2: {
                        int s;
                        Graph T(G.V,G.V-1);
                        cout << "Enter the source point:";
                        cin >> s;
                        Initialize_for_BFS(G,s);
                        T = DFS(G,s);
                        T.printGraph();
                        break;
                    }
            case 3: {
                        int s,r;
                        cout << "Enter the source point:";
                        cin >> s;
                        cout << "Enter the reach point:";
                        cin >> r;
                        Initialize_for_BFS(G,s);
                        if(DFS(G,s,r))
                            cout <<"Reachable"<< endl;
                        else
                            cout <<"Not reachable"<< endl;
                        break;
                    }
            case 4: exit(0);
            default: cout<<"Invalid operation !!"<< endl;
        }
        cout << endl;
    }
    return 0;
}

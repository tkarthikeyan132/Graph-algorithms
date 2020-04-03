#include"Module4.h"
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
        cout <<"Operations:\n1.Test_bipartite(it return whether the given graph G is bipartite or not\n2.Test_articulationpoints(it returns a vector of articulation points)\n3.Test_bridges(it returns a vector of bridges)\n4.Exit\nEnter your choice:";
        cin >>swh;
        switch( swh )
        {
            case 1: {
                        if(Test_bipartite(G))
                            cout <<"Graph is bipartite" << endl;
                        else
                            cout <<"Graph is not bipartite" << endl;
                        break;
                    }
            case 2: {
                        vector <int> rap; // required articulation point vector
                        rap = Test_articulationpoints(G);
                        cout << "Number of articulation points:";
                        cout << rap.size() << endl;
                        cout <<"Articulation points are:";
                        for(int k=0;k<rap.size();k++)
                            cout <<k<< " ";
                        cout << endl;
                        break;
                    }
            case 3: {
                        vector <pair<int,int>> rb; // required bridges vector
                        rb = Test_bridges(G);
                        cout << "Number of bridges:";
                        cout << rb.size() <<endl;
                        cout <<"Bridges are:";
                        for(auto k=rb.begin();k<rb.end();k++)
                            cout <<k->first<< " " <<k->second << endl;
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

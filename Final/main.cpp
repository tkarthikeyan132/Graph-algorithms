#include"GraphSTL.h"
int main()
{
    int v,e,src,dest,wt;
    cout<<"Enter no. of vertices:"<<endl;
    cin>>v;
    cout<<"Enter no. of edges:"<<endl;
    cin>>e;
    Graph graph(v,e);
    for (int i = 0; i < graph.E; i++)
    {
        cout<<"Edge "<<i+1<<":\nSource:"<<endl;
        cin>>src;
        cout<<"Destination:"<<endl;
        cin>>dest;
        cout<<"Weight:"<<endl;
        cin>>wt;
        if(src>-1 && dest >-1 && src<graph.V && dest<graph.V)
        graph.addUEdge(src,dest,wt);
    }
    graph.printGraph();
    return 0;
}
#include"Module5.h"
using namespace std;
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
    cout<<"BFS result:"<<endl;
    BFS(graph);
    cout<<endl;
    int s,r;
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"BFS result:"<<endl;
    Graph T=BFS(graph,s);
    T.printGraph();
    cout<<endl;
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"Enter the vertex where you want to reach:";
    cin>>r;
    cout<<"BFS result:"<<endl;
    if(BFS(graph,s,r))
        cout<<"reachable";
    else
        cout<<"not reachable";
    cout<<endl;
    return 0;
    cout<<"DFS result:"<<endl;
    DFS(graph);
    cout<<endl;
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"Enter the vertex where you want to reach:";
    cin>>r;
    cout<<"DFS result:"<<endl;
    if(DFS(graph,s,r))
        cout<<"reachable";
    else
        cout<<"not reachable";
    cout<<endl;
    if(Test_bipartite(graph))
        cout<<"Graph is bipartite"<<endl;
    else
        cout<<"Graph is not bipartite"<<endl;
    Graph MST = MST_Kruskal(graph);
	MST.printGraph();
    MST = MST_youralgo(graph);
	MST.printGraph();
    graph.printGraph();
    return 0;
}
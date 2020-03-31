// C++ program to represent undirected and weighted graph 
// using STL. The program basically prints adjacency list 
// representation of graph 

#include <iostream>
#include <vector> 
using namespace std; 
class Graph
{
	public:
        int V;
        int E;
        vector<pair<int, int> > adj[20]; //makes an array of vectors

        //Adding an edge between vertex u and v.
        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
            adj[v].push_back(make_pair(u, wt)); //remove this for directed graphs
        } 

        // Print adjacency list representaion ot graph 
        void printGraph() 
        {  
            for (int u = 0; u < V; u++) 
            { 
                cout << "Node " << u << " makes an edge with \n"; 
                for (auto it = adj[u].begin(); it != adj[u].end(); it++) 
                {  
                    cout << "\tNode " << it->first << " with edge weight ="
                        << it->second << endl;   
                        /*'it->first' is used becauseiterator 'it' is basically 
                        a pointer pointing to the 'it'th pair of 'u'th vector present in the array 'adj' of vectors.*/
                } 
                cout << endl; 
            } 
        }
};
 
 


int main() 
{ 
	Graph G;
	G.V = 5; 
	G.addEdge(0, 1, 10); 
	G.addEdge(0, 4, 20); 
	G.addEdge(1, 2, 30); 
	G.addEdge(1, 3, 40); 
	G.addEdge(1, 4, 50); 
	G.addEdge(2, 3, 60); 
	G.addEdge(3, 4, 70);
	G.printGraph(); 
	return 0; 
} 



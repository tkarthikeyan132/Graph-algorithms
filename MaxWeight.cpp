#include <bits/stdc++.h>

using namespace std; 

#define V 5   //No of vertices of the graph


int minKey(int key[], bool mstSet[]) 
{
   int min = INT_MAX, min_index;    //Intializing min to infinity

   for (int v = 0; v < V; v++)  
     {
       if (mstSet[v] == false && key[v] < min)      //min_index contains the vertex which has min-key
            min = key[v], min_index = v;  
     }
   
   return min_index;


}

void printMST(int parent[], int graph[V][V]) 
{
   cout<<"Edge \tWeight\n"; 

   for (int i = 1; i < V; i++) 
     cout<<parent[i]<<" - "<<i<<" \t"<<-1*(graph[i][parent[i]])<<" \n"; 

}

void primMST(int graph[V][V])  
{
   int parent[V];       //MST is stored
 
   int key[V];         //Min Key Values to maintain Weights

   bool mstSet[V];     //To pair up what are visited

    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;     //All key values are set to infinite and mstSET is made false for all

     key[0] = 0;                   //Starting with the 1st vertex
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
   {
        int u = minKey(key, mstSet);   //Picking the min vertex from the set of vertices not included yet
     
       mstSet[u] = true;              //Placing that value 

       //Now its important to update the Adjacent vertices of the selected vertex,Should be careful of Already visited vertex
        
       for (int v = 0; v < V; v++)  
      {
           //The first condition in the "and" checks whether an edge exsits and the second whether the vertex is visited or not 
           // And then we check the weights of the key value and graph value comparing between them
             if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])    
				parent[v] = u, key[v] = graph[u][v]; 
      
             
      }


   }

    printMST(parent, graph);
}

int main()  
  
{  
    int graph[V][V];
    int gra;
    
    printf("Enter the edges between %d vertices \n ",V);
    printf("\n enter 0 if no edge exists \n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("\n Edge between %d & %d  \n",i,j);
            scanf("%d",&gra);
            graph[i][j]=-gra;
        }
    }
    primMST(graph);  
  
    return 0;  
}  

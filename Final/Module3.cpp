#include"Module3.h"

int Zero_In_degree = 0;   //a utility global variable for DAG.

vector<vector<int>> BFS_SPATH(Graph G, Vertex s, int flag)
{
    int u;
    queue <int> Q;
    Q.push(s.id);

    if(flag == 0)
    {
        vector <vector <int>> spath (G.V); 
        Vertex Array_of_vectors[G.V];
        for(int i = 0; i < G.V; i++)
        {
            Array_of_vectors[i].id = i;
            if(i != s.id)
            {
                Array_of_vectors[i].dist = INFINITY;
                Array_of_vectors[i].pid = -2;
                Array_of_vectors[i].color = 0; //white
            }
            else
            {
                Array_of_vectors[i].color = 1;  //gray
                Array_of_vectors[i].dist = 0;
                Array_of_vectors[i].pid = G.V;  //sort of NIL an indication of having no parent.
            }
        }
    
        while(!Q.empty())
        {
            u = Q.front();
            Q.pop();
            for(auto it = G.BFS_SPATH_adj[u].begin(); it < G.BFS_SPATH_adj[u].end(); it++)
            {  
                if(Array_of_vectors[*it].color == 0)
                {
                    Array_of_vectors[*it].color = 1;
                    Array_of_vectors[*it].dist = Array_of_vectors[u].dist + 1;
                    Array_of_vectors[*it].pid = u; 
                    Q.push(Array_of_vectors[*it].id);
                }
            }
            Array_of_vectors[u].color = 2;
        }
        //below part is just to make a ordered collection of parents, done for every node. 
        u = 0;
        spath[s.id].push_back(-2);
        while(u != G.V)
        {
            int i = u;
            while(Array_of_vectors[i].pid != G.V)
            {
                if(Array_of_vectors[u].pid != -2)
                {
                    spath[u].push_back(Array_of_vectors[i].pid);
                    i = Array_of_vectors[i].pid;
                }
                else
                {
                    spath[u].push_back(INFINITY);
                    break;
                }
            }
            spath[u].push_back(-1); //to pad -1 for indication of end
            u++;
        }
        return spath;
    }
    else
    {
        vector <vector <int>> spath (G.V_Prime); 
        Vertex Array_of_vectors[G.V_Prime];
        for(int i = 0; i < G.V_Prime; i++)
        {
            Array_of_vectors[i].id = i;
            if(i != s.id)
            {
                Array_of_vectors[i].dist = INFINITY;
                Array_of_vectors[i].pid = -2;
                Array_of_vectors[i].color = 0; //white
            }
            else
            {
                Array_of_vectors[i].color = 1;  //gray
                Array_of_vectors[i].dist = 0;
                Array_of_vectors[i].pid = G.V_Prime;  //sort of NIL an indication of having no parent.
            }
        }
    
        queue <int> Q;
        Q.push(s.id);
        while(!Q.empty())
        {
            u = Q.front();
            Q.pop();
            for(auto it = G.BFS_SPATH_adj[u].begin(); it < G.BFS_SPATH_adj[u].end(); it++)
            {  
                if(Array_of_vectors[*it].color == 0)
                {
                    Array_of_vectors[*it].color = 1; 
                    Array_of_vectors[*it].dist = Array_of_vectors[u].dist + 1;
                    Array_of_vectors[*it].pid = u; 
                    Q.push(Array_of_vectors[*it].id);
                }
            }
            Array_of_vectors[u].color = 2;
        }

        //below part is just to make a ordered collection of parents, done for every node. 
        u = 0;
        spath[s.id].push_back(-2); //spath of the source Vertex itself is kept as negative.
        while(u != G.V_Prime)
        {
            if(u < G.V)   //ensuring we don't push dummy_vertices.
            {
                int i = u;
                while(Array_of_vectors[i].pid != G.V_Prime)
                {
                    if(Array_of_vectors[u].pid != -2) //check if the Vertex u is traversed using BFS or not.
                    {
                        if(Array_of_vectors[i].pid < G.V)
                            spath[u].push_back(Array_of_vectors[i].pid);
                        i = Array_of_vectors[i].pid;
                    } 
                    else //if it is not traversed, put infinity in its spath
                    {
                        spath[u].push_back(INFINITY);
                        break;
                    }
                }
                spath[u].push_back(-1); //to pad -1 for indication of end
            }
            u++;
        }
        return spath;
    }
}

vector<int> LPATH(Graph &G, int flag)
{
    if (flag == 0) //for an unweighted tree
    {
        int max_dist = 0;
        vector<int> Final_vector(G.V + 1);
        int deepest_node_id = 0; //first_end_of_lpath_id
        int second_end_of_lpath_id = 0;
        Initialize_for_BFS(G, 0);
        BFS(G, 0);
        for (int i = 0; i < G.V; i++)
        {
            if (max_dist < G.Vertex_Array[i].dist)
            {
                max_dist = G.Vertex_Array[i].dist;
                deepest_node_id = i;
            }
        }
        max_dist = 0;
        Initialize_for_BFS(G, deepest_node_id);
        BFS(G, deepest_node_id);
        for (int i = 0; i < G.V; i++)
        {
            if (max_dist < G.Vertex_Array[i].dist)
            {
                max_dist = G.Vertex_Array[i].dist;
                second_end_of_lpath_id = i;
            }
        }
        int i = second_end_of_lpath_id;
        int j = 1;
        while (G.Vertex_Array[i].id != deepest_node_id)
        {
            Final_vector[j] = i;
            i = G.Vertex_Array[i].pid;
            j++;
        }
        Final_vector[0] = j - 1;
        Final_vector[j] = i;
        Final_vector.resize(j + 1);
        return Final_vector;
    }

    else // for a DAG
    {
        int MAX = 0;
        int source_of_lpath = 0;
        vector<int> Topological_Vector(G.V);
        vector<int> Final_Vector(G.V + 1);
        for (int i = 0; i < G.V; i++)
        {
            for (auto it = G.adj[i].begin(); it != G.adj[i].end(); it++)
            {
                it->second = (-1) * it->second; //negating the weights.
            }
        }
        Topological_Vector = topological_ordering(G); //determines the Zero_In_degree.
        vector<int> LPATH_Vector[Zero_In_degree];     //vector array
        for (int i = 0; i < Zero_In_degree; i++)
        {
            LPATH_Vector[i].resize(G.V + 1);
            LPATH_Vector[i] = DAG_LONGEST_PATH(G, G.Vertex_Array[Topological_Vector[i]], Topological_Vector);
            if (LPATH_Vector[i][0] < MAX)
            {
                MAX = LPATH_Vector[i][0];
                Final_Vector = LPATH_Vector[i];
                source_of_lpath = Topological_Vector[i];
            }
        }
        //__________work is done till now, the structure of the vector is now arranged to return in a proper way.
        Final_Vector[0] = (-1) * Final_Vector[0]; //making the length of the longest path positive.
        for (int i = 1; i < G.V + 1; i++)
        {
            if (Final_Vector[i] == source_of_lpath)
            {
                Final_Vector.resize(i + 1);
                break;
            }
        }
        return Final_Vector; //remember the first element contains the longest path.
    }
}


vector<int> topological_ordering(Graph &G)
{
    queue<int> q;
    vector<int> Topological_Vector(G.V);
    int counter = 0;
    for (int i = 0; i < G.V; i++)
    {
        if (G.Vertex_Array[i].In_Degree == 0)
            q.push(i);
    }
    Zero_In_degree = q.size(); //used to mark where the cluster of zero in degree vertices ends in the Topological_Vector.
    while (!q.empty())
    {
        int y = q.front();
        q.pop();
        G.Vertex_Array[y].Topological_Number = counter;
        Topological_Vector[counter] = y;
        counter++;
        for (auto it = G.adj[y].begin(); it != G.adj[y].end(); it++)
        {
            G.Vertex_Array[it->first].In_Degree--;
            if (G.Vertex_Array[it->first].In_Degree == 0)
                q.push(it->first);
        }
    }
    if (counter != G.V)
        cout << "cycle found !!" << endl;
    return Topological_Vector;
}

vector<int> DAG_LONGEST_PATH(Graph &G, Vertex s, vector<int> Topological_vector)
{
    vector<int> LPATH(G.V + 1);
    int Max_length = 0;
    int Max_leaf = 0;
    for (int i = 0; i < G.V; i++) //Initialize single source
    {
        if (i != s.id)
        {
            G.Vertex_Array[i].dist = INFINITY;
            G.Vertex_Array[i].pid = -2;
        }
        else
        {
            G.Vertex_Array[i].dist = 0;
            G.Vertex_Array[i].pid = G.V;
        }
    }
    for (int i = 0; i < G.V; i++) //RELAX every edge emerging from Topological_vector[i]
    {
        int u = Topological_vector[i]; //accessing the vertices in the toplogical manner.
        for (auto it = G.adj[u].begin(); it != G.adj[u].end(); it++)
        {
            if (G.Vertex_Array[it->first].dist > G.Vertex_Array[u].dist + it->second)
            { //it->second corresponds to the weight of edge (u)---->(it->first)
                G.Vertex_Array[it->first].dist = G.Vertex_Array[u].dist + it->second;
                G.Vertex_Array[it->first].pid = u;
            }
        }
    }

    for (int i = 0; i < G.V; i++)
    {
        if (G.Vertex_Array[i].dist < Max_length) //all weights are negative thus used '<' symbol.
        {
            Max_length = G.Vertex_Array[i].dist; //our Max_length is actually Min_length.
            Max_leaf = i;                        //Max_lenght is basically negated Maximum length of the path.
        }
    }

    LPATH[0] = G.Vertex_Array[Max_leaf].dist;
    int i = Max_leaf;
    int j = 1;
    while (G.Vertex_Array[i].pid != G.V)
    {
        LPATH[j] = i;
        i = G.Vertex_Array[i].pid;
        j++;
    }
    LPATH[j] = i;
    return LPATH;
}
Graph MAX_Weight_MST(Graph G)
{
    for(int u=0;u<G.V;u++)
    {
        for(auto it=G.adj[u].begin();it!=G.adj[u].end();it++)
        it->second=(-1)*it->second;
    }
    Graph temp=MST_Prim(G);
    for(int u=0;u<temp.V;u++)
    {
        for(auto it=temp.adj[u].begin();it!=temp.adj[u].end();it++)
        it->second=(-1)*it->second;
    }
    return temp;
}
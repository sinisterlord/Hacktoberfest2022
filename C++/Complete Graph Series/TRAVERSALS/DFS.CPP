// G[V,E]
#include <bits/stdc++.h>
using namespace std;

// DFS TRAVERSAL

vector<int> DFS;

void getbfs(int src, vector<int> &visited, vector<int> G[])
{
    visited[src] = 1;
    DFS.push_back(src);
    for (auto val : G[src])
    {
        if (!visited[val])
        {
            getbfs(val, visited, G);
        }
    }
}

vector<int> DFStraversal(int V, vector<int> G[])
{ //source node req let it be 0
    vector<int> visited(V, 0);
    getbfs(0, visited, G);

    for (auto v : DFS)
    {
        cout << " " << v;
    }
    return DFS;
}

main()
{
    int vertex;
    cout << "\n V: ";
    cin >> vertex;
    int edges;
    cout << "\n E: ";
    cin >> edges;

    vector<int> G[vertex]; // 0 BASED INDEXING

    for (int i = 0; i < edges; i++)
    {
        int nd1;
        int nd2;
        cin >> nd1 >> nd2;

        G[nd1].push_back(nd2);
        G[nd2].push_back(nd1);
    }

    cout << "\nTHE GRAPH IS : \n";

    for (int i = 0; i < vertex; i++)
    {
        cout << i << "--->  ";
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    }

    DFStraversal(vertex, G);
}

 void dfs( int src ,vector<int> &DFS, vector<int> adj[] 
    ,vector<int> &visited  )
    {
        visited[src] = 1;
        DFS.push_back(src);
        
        for(auto x:adj[src] )
        {
            if(!visited[x])
            {
                dfs(x,DFS,adj , visited);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V,0);
        vector<int> DFS;
        dfs(0,DFS,adj , visited);
        
         return DFS;
    }

//  V: 5

//  E: 4
// 0 1
// 0 2
// 0 4
// 4 3

// THE GRAPH IS :
// 0--->   1 2 4
// 1--->   0
// 2--->   0
// 3--->   4
// 4--->   0 3


//  0 1 2 4 3
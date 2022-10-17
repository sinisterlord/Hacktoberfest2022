#include <bits/stdc++.h>
using namespace std;

// given graph undirected
//find cycle present in it

//approach :  we will keep track of the visited nodes and also the parent node
// if a node within a traversal is not parent of the previos node and also is a visited node then we can say the graph contains cycle
//DFS TRAVERSAL WOULD BE FOLLOWED

bool dfs(int src, int parent, vector<int> &visited, vector<int> G[])
{
    visited[src] = 1;
    for (auto x : G[src])
    {
        if (!visited[x])
        {
           if(dfs(x, src, visited, G)) 
                 return true;
        }
        else if (x != parent)
        {
            return true;
        }
    }

    return false;
}

bool ISGRAPHCYCLIC(vector<int> G[], int V)
{
    vector<int> visited(V, 0);
  for (int i = 0; i < V; i++)
  {
      if(!visited[i])
      {
          bool f =  dfs(i ,-1 , visited , G );
          if(f) return true;
      }
  }

  return false;
  
}
main()
{
    int vertex;
    cout << "\n V: ";
    cin >> vertex;
    int edges;
    cout << "\n E: ";
    cin >> edges;

    vector<int> G[vertex];

    for (int i = 0; i < edges; i++)
    {
        int nd1;
        int nd2;
        cin >> nd1 >> nd2;

        G[nd1].push_back(nd2);
        G[nd2].push_back(nd1);
    }

    cout << "\nTHE GRAPH IS : \n";

    for (int i = 0; i <vertex; i++)
    {
        cout << i << "--->  ";
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    
    }

cout<<"the graph contains cycle or not : "<<ISGRAPHCYCLIC(G ,vertex);

}
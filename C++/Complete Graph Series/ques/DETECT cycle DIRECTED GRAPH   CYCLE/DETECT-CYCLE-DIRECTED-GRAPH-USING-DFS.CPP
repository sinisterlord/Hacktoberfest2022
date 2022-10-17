#include <bits/stdc++.h>

using namespace std;
//DFS

// APPROACH WE WILL MAINTAIN 2 VECOTOR ORDER AND VISITED ONEWOULD MARK THE VISITED NODE AND OTHER WOUL CHANGE ACC TO RECURSION
// TRACING AND MARKING VIVTED AND ORDER TOGETHER
// //WHEN WE WILL TRACE BACK RECURSION THEB WE WILL PUT 0 AT ALOCATION//BACKTRACK
// AND WE WILL CHECK FOR A NODE WHICH NOT OCCURS IN RECURSION TRACEBACK AND AND ALSO IS VISITED MEANS ORDERVAL =1 VISITEDVAL = 1 AND  OCCURING IN SUB RECURSION STEP

bool dfs(int src, vector<int> &order, vector<int> &visited, vector<int> G[])
{
    visited[src] = 1;
    order[src] = 1;

    for (auto x : G[src])
    {
        if (!visited[x])
        {
            bool cf = dfs(x, order, visited, G);
            if (cf)
                return true;
        }
        else if (order[x] == 1)
        {
            return true;
        }
    }
    order[src] = 0;
    return false;
}

bool detectCycleDIRECTED(vector<int> G[], int V)
{
    vector<int> visited(V, 0);
    vector<int> order(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool f = dfs(i, order, visited, G);
            if (f)
            {
                return true;
            }
        }
    }

    return false;
}

main()
{
    cout << " DIRECTED GRAPH \n ";
    int V;
    int E;
    cout << " enter V and E : ";
    cin >> V >> E;
    vector<int> G[V]; // 0 IS ALSO HERE

    for (int i = 0; i < E; i++)
    {
        int x;
        int y;
        //    x to y   x->y  y neighbour of x
        cin >> x >> y;
        G[x].push_back(y);
    }

    cout << "\nDirected  graph is : \n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    }

    cout << "the following directed graph contains the cycle :" << detectCycleDIRECTED(G, V);
}

//   enter V and E : 5 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 2 4

// Directed  graph is :
// 0 -->  1
// 1 -->  2
// 2 -->  3 4
// 3 -->  1 4
// 4 -->
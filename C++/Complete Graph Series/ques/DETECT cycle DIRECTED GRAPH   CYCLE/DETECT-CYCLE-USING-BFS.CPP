#include <bits/stdc++.h>

using namespace std;

// USING BFS AND TOPOSORT
//WEWILL DEFINITELY FOUND SOME NODES WHO DONOT HAVE INDERGEE LEFT AS ZERO EVEN AFTER REMOVING OTHERS THENWE CAN SAY THAT THIS FORMS A CYCLE

bool CHECKCYCLEDIRECTED(vector<int> G[], int V)
{

    vector<int> indegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto v : G[i])
        {
            indegree[v]++;
        }
    }
    int c = 0;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            c++;
        }
    }

    while (!q.empty())
    {
        int td = q.front();
        q.pop();
        for (auto x : G[td])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
                c++;
            }
        }
    }

    if (c != V)
        return true;

    else
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
#include <bits/stdc++.h>

using namespace std;
//topology sort is sorting based on indegree of a node in a given graph directed
//indegree is the count of total nodes pointing to that node
//
//in topology sort we search for the node having min indegree then weprint that node and remove that edge then we recalculate indegree of other nodes
//and repeat same procedure

vector<int> Toposort(vector<int> G[], int V)
{
    vector<int> indegree(V, 0);
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        for (auto x : G[i])
        {
            indegree[x]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int td = q.front();
        q.pop();
        ans.push_back(td);
        for (auto x : G[td])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    cout << "the topo sort is :\n";
    for (auto i : ans)
    {
        cout << "  " << i;
    }

    return ans;
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

    Toposort(G, V);
}

// BFS ALGO  IT USES
// QUEUE

// G[V,E]

#include <bits/stdc++.h>
using namespace std;

// SPACE O(V)
// TIME O(V + E)
//

vector<int> BFStraversal(int vertex, vector<int> G[])
{
    vector<int> visited(vertex + 1, 0); // 1 BASED INDEXING
    queue<int> q;
    vector<int> BFS;
    q.push(1); // FIRST STARTING ELEMENT

    visited[1] = 1;

    while (!q.empty())
    {
        int td = q.front();
        q.pop();
        BFS.push_back(td);

        for (auto val : G[td])
        {
            if (!visited[val])
            {
                visited[val] = 1;
                q.push(val);
            }
        }
    }

    for (auto val : BFS)
    {
        cout << "  " << val;
    }

    return BFS;
}

main()
{
    int vertex;
    cout << "\n V: ";
    cin >> vertex;
    int edges;
    cout << "\n E: ";
    cin >> edges;

    vector<int> G[vertex + 1];

    for (int i = 0; i < edges; i++)
    {
        int nd1;
        int nd2;
        cin >> nd1 >> nd2;

        G[nd1].push_back(nd2);
        G[nd2].push_back(nd1);
    }

    cout << "\nTHE GRAPH IS : \n";

    for (int i = 1; i <= vertex; i++)
    {
        cout << i << "--->  ";
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    }

    BFStraversal(vertex, G);
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> BFS;
    vector<int> visited(V, 0);

    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        BFS.push_back(temp);
        for (auto x : adj[temp])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }

    return BFS;
}

// input

//  V: 5

//  E: 6
// 1 2
// 2 3
// 3 4
// 4 5
// 1 5
// 2 4

// output

// THE GRAPH IS :
// 1--->   2 5
// 2--->   1 3 4
// 3--->   2 4
// 4--->   3 5 2
// 5--->   4 1

#include <bits/stdc++.h>

using namespace std;

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
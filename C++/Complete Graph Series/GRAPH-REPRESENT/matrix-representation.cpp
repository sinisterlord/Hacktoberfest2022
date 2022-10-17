// G[V,E]
#include <bits/stdc++.h>
using namespace std;

// ADJACENCY matrix
//O(V^2)  TIME
//
main()
{
    int vertex;
    cout << "\n V: ";
    cin >> vertex;
    int edges;
    cout << "\n E: ";
    cin >> edges;

    int G[vertex + 1][vertex + 1];

    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int nd1;
        int nd2;
        cin >> nd1 >> nd2;
        G[nd1][nd2] = 1;
        G[nd2][nd1] = 1;
    }

    cout << "\nTHE GRAPH IS : \n";

    for (int i = 1; i <= vertex; i++)
    {
        cout << i << "--->  ";
        for (int j = 1; j <= vertex; j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    }
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
// 1--->   0 1 0 0 1
// 2--->   1 0 1 1 0
// 3--->   0 1 0 1 0
// 4--->   0 1 1 0 1
// 5--->   1 0 0 1 0
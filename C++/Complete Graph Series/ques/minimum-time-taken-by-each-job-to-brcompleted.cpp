#include <bits/stdc++.h>

using namespace std;
///acyclic graph

//completion time of a node depends on the node from which it is being pointed
// we will take unit time for the starting  0 indegree nodes
//then we will calculate time ofother based on it  e g if 1 and 2 points to 3 then completion of 3 would depnd on completion of 1 and 2

// node time =  parent node time  + 1

//follow topo sort and updte time matrix

main()
{
    cout << " DIRECTED GRAPH \n ";
    int V;
    int E;
    cout << " enter V and E : ";
    cin >> V >> E;
    vector<int> G[V]; // 0 IS ALSO HERE
    vector<int> indegree(V,0);
    for (int i = 0; i < E; i++)
    {
        int x;
        int y;
        //    x to y   x->y  y neighbour of x
        cin >> x >> y;
        G[x].push_back(y);
        indegree[y]++;
    }

    cout << "\nDirected  graph is : \n";
cout<<"if a value comes in adjacency list of the node then we can say that  the arrow fromit is";
    for(int i = 0; i < V; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << " " << G[i][j];
        }
        cout << endl;
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            ans[i] = 1;
            q.push(i);
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
                ans[x] = 1 + ans[td]; //1 + parent
                q.push(x);
            }
        }
    }

cout<<" the time taken by each is : ";
    for(auto i : ans)
    {
        cout<<" "<<i;
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
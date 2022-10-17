// G[V,E]
#include <bits/stdc++.h>
using namespace std;

// ADJACENCY LIST
//O(V + E)  TIME
//
main()
{
    int vertex;
    cout<<"\n V: ";
    cin >> vertex;
    int edges;
        cout<<"\n E: ";
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


    cout<<"\nTHE GRAPH IS : \n";

    
      for (int i = 1; i <= vertex; i++)
      {
         cout<<i<<"--->  ";
         for (int j = 0; j < G[i].size() ; j++)
         {
            cout<<" "<<G[i][j];
         }
         cout<<endl;


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
// 1--->   2 5
// 2--->   1 3 4
// 3--->   2 4
// 4--->   3 5 2
// 5--->   4 1

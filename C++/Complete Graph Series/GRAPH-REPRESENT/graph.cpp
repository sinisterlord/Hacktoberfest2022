#include <bits/stdc++.h>
using namespace std;

class Graphnode
{
public:
    int nodeval;
    vector<Graphnode *> neighbours;
    Graphnode()
    {
        nodeval = 0;
        neighbours = vector<Graphnode *>();
    }
    Graphnode(int val)
    {
        nodeval = val;
        neighbours = vector<Graphnode *>();
    }
    Graphnode(int val, vector<Graphnode *> n)
    {
        nodeval = val;
        neighbours = n;
    }

   
};

main()
{
Graphnode* G = new Graphnode(23);
Graphnode *G2 = new Graphnode(4);
Graphnode *G1 = new Graphnode(42 ,{G,G2});




// BIDIRECTIONAL DIRECTD GRAPH

    G->neighbours.push_back(G1);
    G->neighbours.push_back(G2);

    G2->neighbours.push_back(G);  
    
    G2->neighbours.push_back(G1);



    
}
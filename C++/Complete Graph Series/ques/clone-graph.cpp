#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// use dfs and create a clone to each node and store
// make old to new node to node vector /map 
// follow dfs make neighbors of curr node
//if node is visited to put it in neighbour of other use node to node visited vector

Node *createclone(Node *curr, vector<Node *> &visited)
{
    Node *copy = new Node(curr->val);
    visited[curr->val] = copy;

    for (auto x : curr->neighbors)
    {
        if (!visited[x->val])
        {
            copy->neighbors.push_back(createclone(x, visited));
        }
        else
        {
            copy->neighbors.push_back(visited[x->val]);
        }
    }
    return copy;
}

Node *cloneGraph(Node *node)
{
    // STORE THE NEW CREATED NODE IN VISITED CORRESPONDING TO PREV NODE VAL
    if (!node)
    {
        return node;
    }
    vector<Node *> visited(101, NULL);
    Node *clone = createclone(node, visited);

    return clone;
}




//better waay
void clonegraph(Node* node,map<Node*,Node*>& mp,
map<Node*,bool>& vis){
        if(!node || vis[node]) return;
        vis[node]=true;
        for(auto x:node->neighbors){
            if(!mp[x]) mp[x]=new Node(x->val);
            mp[node]->neighbors.push_back(mp[x]);
            //cout<<x->val<<" "<<vis[x]<<endl;
            clonegraph(x,mp,vis);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<Node*,Node*> mp;
        map<Node*,bool> vis;
        mp[node]=new Node(node->val);
        clonegraph(node,mp,vis);
        return mp[node];
    }
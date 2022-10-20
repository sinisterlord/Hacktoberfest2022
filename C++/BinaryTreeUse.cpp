#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printLevelWise(BinaryTreeNode<int> *root) 
{
	if (root == NULL) {
		return;
	}
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        cout << q.front()->data << ":";
		if (q.front()->left != NULL) {
			cout << "L:" << q.front()->left->data<<",";
            q.push(q.front()->left);
		}
        else cout<<"L:-1,";
		if (q.front()->right != NULL) {
			cout << "R:" << q.front()->right->data;
            q.push(q.front()->right);
		}
        else cout<<"R:-1";
		cout << endl;
		q.pop();
    }
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}
	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	queue<BinaryTreeNode<int>*> q;

	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


int main() {
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}


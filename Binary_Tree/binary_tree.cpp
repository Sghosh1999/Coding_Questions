//Creating a Binary tree

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    //Constructor
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

//Building the Binary tree
Node *buildTree()
{

    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
//Print the preorder traversal of the tree
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    Node *root = buildTree();
    preOrder(root);
}
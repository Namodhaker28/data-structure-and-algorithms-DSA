#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *LCA(node *root, int n2, int n1)
{
    if (root == NULL)
        return NULL;

    if (root->data == n2 || root->data == n1)
        return root;

    node *leftLCA = LCA(root->left, n2, n1);
    node *rightLCA = LCA(root->right, n2, n1);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA == NULL)
        return rightLCA;

    return leftLCA;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->left->left=new node(8);
    root->right->right = new node(7);

    node *lca = LCA(root, 7, 8);

    if (lca)
        cout << lca->data;
    else
        cout << "undefined";

    return 0;
}
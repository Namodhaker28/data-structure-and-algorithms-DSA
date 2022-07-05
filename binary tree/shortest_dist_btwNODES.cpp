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

node* LCA(node* root,int n1,int n2)
{
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;

    node* leftLCA=LCA(root->left,n1,n2);
    node* rightLCA=LCA(root->right,n1,n2);

    if(leftLCA&& rightLCA)
    return root;

    if(leftLCA==NULL)
    return LCA(root->right,n1,n2);;

    return LCA(root->left,n1,n2);;
}

int distance(node* root,int key,int dist)
{
    if(root==NULL)
    return -1;

    if(root->data==key)
    return dist;

    int ld=distance(root->left,key,dist+1);

    if(ld!=-1)
    return ld;

    return distance(root->right,key,dist+1);
}

int Sdist(node* root,int n1,int n2)
{
    node* lca=LCA(root,n1,n2);

    
    int d1=distance(lca,n1,0);
    int d2=distance(lca,n2,0);

    return d1+d2;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<Sdist(root,4,2);

    return 0;
}
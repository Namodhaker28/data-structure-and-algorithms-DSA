#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    node* left;
    node *right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isBST(node* root,node* min=NULL,node* max=NULL)
{
    if(root==NULL)
    return true;

    if(min!=NULL && root->data<=min->data)
    return false;
    if(max!=NULL && root->data>=max->data)
    return false;

    bool leftcheck=isBST(root->left,min,root);
    bool rightcheck=isBST(root->right,root,max);

    if(leftcheck&&rightcheck)
    return true;
    
    return false;

}

int main()
{
    node* root=new node(2);
    root->left=new node(1);
    root->right=new node(3);

    if(isBST(root,NULL,NULL))
    cout<<"valid";
    else
    cout<<"not-valid";
    return 0;
}
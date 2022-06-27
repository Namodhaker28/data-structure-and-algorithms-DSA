#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
    {
        int data;
        node* left;
        node* right;

        node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
    };

    bool checkbalance(node* root, int *height)
    {
        if(root==NULL)
        return true;

        int lh=0,rh=0;
        if(checkbalance(root->left, &lh)==false)
        return false;
        if(checkbalance(root->right, &rh)==false)
        return false;

        *height=max(lh,rh)+1;

        if(abs(lh-rh)<=1)
        return true;
        else
        return false;
    }
    

int main()
{
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);


    int height=0;
    if(checkbalance(root,&height))
    cout<<"balanced";
    else
    cout<<"unblanced";

    return 0;
}

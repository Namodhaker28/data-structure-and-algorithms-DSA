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

    node * BuildBST(int preorder[],int * idx,int key,int min,int max,int n)
    {
        if(*idx>=n)
        return NULL;

        node* root=NULL;

        if(key>min && key<max)
        {
            root=new node(key);
            *idx=*idx+1;

            if(*idx<n)
            root->left=BuildBST(preorder,idx,preorder[*idx],min,key,n);
            if(*idx<n)
            root->right=BuildBST(preorder,idx,preorder[*idx],key,max,n);

        }
         return root;
        
    }

    void printPreorder(node* root)
    {
        if(root==NULL)
        return ;

        cout<<root->data<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    int main()
    {
        int preorder[]={10,2,1,13,11};
        int idx=0;
        int n=5;

        node* root=BuildBST(preorder,&idx,preorder[0],INT_MIN,INT_MAX,n);
        printPreorder(root);
        return 0;
    }
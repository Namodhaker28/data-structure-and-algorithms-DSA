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

    node* buildBST(node* root,int val)
    {
        if(root==NULL)
        return new node(val);

        if(root->data>val)
        root->left=buildBST(root->left,val);
        else
        root->right=buildBST(root->right,val);

        return root;
    }

    void inorder(struct node* root)
    {
        if(root==NULL)
        return ;

        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }

    int main(){
        struct node* root=new node(5);
        buildBST(root,1);
        buildBST(root,3);
        buildBST(root,4);
        buildBST(root,2);
        buildBST(root,7);

        inorder(root);
        return 0;
    }
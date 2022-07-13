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

    node* SearchBST(node* root,int key)
    {
        if(root==NULL)
        return NULL;

        if (root->data==key)
        return root;

        if(root->data < key)
        return SearchBST(root->right,key);

        return SearchBST(root->left,key);
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
        struct node* root=new node(4);
        root->left=new node(2);
        root->right=new node(5);
        root->left->left=new node(1);
        root->left->right=new node(3);
        root->right->right=new node(6);
        
        node* flag=SearchBST(root,1);
        if(flag==NULL)
        cout<<"not-found";
        else
        cout<<"found";
        return 0;
    }
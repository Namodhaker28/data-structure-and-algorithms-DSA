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

    node * Sucessor(node* root)
    {
        node * curr= root;
        while(curr!=NULL&&curr->left!=NULL)
        curr=curr->left;

        return curr;
    }

    node* DeleteBST(node* root,int key)
    {
        if(root->data < key)
        root->right= DeleteBST(root->right,key);
        else if(root->data>key)
        root->left= DeleteBST(root->left,key);
        else{
            if(root->left==NULL)
            {
                node* temp =root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL)
            {
                node* temp=root->left;
                free(root);
                return temp;
            }

            node * temp=Sucessor(root->right);
            root->data=temp->data;
            root->right=DeleteBST(root->right,temp->data);
            
        }
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
        struct node* root=new node(4);
        root->left=new node(2);
        root->right=new node(5);
        root->left->left=new node(1);
        root->left->right=new node(3);
        root->right->right=new node(6);
        
        inorder(root);
        cout<<endl;
        root=DeleteBST(root,2);
        inorder(root);
        return 0;
    }
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


    void Flatten(node* root)
    {
        if(root==NULL ||( root->left==NULL && root->right==NULL))
        return ;
        
        if(root->left!=NULL)
        {
            Flatten(root->left);
            
            node* temp=root->right;
            root->right=root->left;
            root->left=NULL;

            node* t =root->right;
            while(t->right!=NULL)
            {
                t=t->right;
            }
            t->right=temp;
        }

        Flatten(root->right);
    }

   void inorder(struct node* root)
    {
        if(root==NULL)
        return ;

        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }

    int main()
{
    struct node *root=new node(4);
    root->left=new node(9);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    // root->right->left=new node(6);
    root->right->right=new node(6);

    inorder(root);
    Flatten(root);
    cout<<endl;
    inorder(root);

    return 0;
}
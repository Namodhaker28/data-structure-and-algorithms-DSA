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

    void SubTreenode(node* root,int k)
    {
        if(root==NULL || k<0)
        return ;

        if(k==0)
        {
        cout<<root->data<<"  ";
        return;
        }

        SubTreenode(root->left,k-1);
        SubTreenode(root->right,k-1);
    }

    int PrintNode(node* root,node* target,int k)
    {
        if(root==NULL)
        return -1;

        if(root==target)
        {
           SubTreenode(root,k);
           return 0;
        }

        int ld=PrintNode(root->left,target,k);

        if(ld!=-1)
        {
            if(ld+1 == k)
            cout<<root->data<<" ";
            else
            SubTreenode(root->right,k-ld-2);

            return ld+1;
        }

        int rd=PrintNode(root->right,target,k);

        if(rd!=-1)
        {
            if(rd+1 == k)
            cout<<root->data<<" ";
            else
            SubTreenode(root->left,k-ld-2);

            return ld+1;
        }

        return -1;
        

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

    PrintNode(root,root->left,1);
    return 0;
}
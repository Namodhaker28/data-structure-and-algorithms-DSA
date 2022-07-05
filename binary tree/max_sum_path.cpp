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

    int PathSum(node*root,int &ans)
    {
        if(root==NULL)
        return 0;

        int left=PathSum(root->left,ans);
        int right=PathSum(root->right,ans);

        int MaxAtNode=max(max(left+right+root->data,root->data),max(left +root->data,right+root->data));

        int nodeval=max(root->data,max(left +root->data,right + root->data));
        return nodeval;
    }

    int maxPathSum(node* root)
    {
        int ans=INT_MIN;
        ans=PathSum(root,ans);
        return ans;
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

    cout<<maxPathSum(root);

    return 0;
}

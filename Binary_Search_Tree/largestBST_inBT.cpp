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

    struct info{
        int size;
        int max;
        int min;
        int ans;
        bool isbst;
    };

    info largestBST(node* root)
    {
        if(root==NULL)
        return {0,INT_MIN,INT_MAX,0,true};

        if(root->left==NULL&&root->right==NULL)
        return {1,root->data,root->data,1,true};

        info left=largestBST(root->left);
        info right=largestBST(root->right);

        info curr;

        curr.size=left.size+right.size+1;

        if(left.isbst&&right.isbst&&root->data>left.max&&root->data<right.min)
        {
            curr.min=min(root->data,min(left.min,right.min));
            curr.max=max(root->data,max(left.max,right.max));

            curr.ans=curr.size;
            curr.isbst=true;

            return curr;
        }
        curr.ans=max(left.ans,right.ans);
        curr.isbst=false;

        return curr;

    }

    int main(){
        struct node* root=new node(12);
        root->left=new node(9);
        root->right=new node(15);
        root->left->left=new node(5);
        root->left->right=new node(10);

        cout<<largestBST(root).ans;

        return 0;
    }
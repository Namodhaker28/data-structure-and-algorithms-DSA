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

    void ZigZag(node * root)
    {
        if(root==NULL)
        return;

        stack<node* > currLevel;
        stack<node* > nextLevel;
        bool l2r=true;

        currLevel.push(root);

        while(!currLevel.empty())
        {
            node* temp=currLevel.top();
            currLevel.pop();

            if(temp)
            {
            cout<<temp->data<<" ";
            
            if(l2r)
            {
                if(temp->left)
                nextLevel.push(temp->left);
                if(temp->right)
                nextLevel.push(temp->right);
            }
            else
            {
                
                if(temp->right)
                nextLevel.push(temp->right);
                if(temp->left)
                nextLevel.push(temp->left);
            }
            
            }
            if(currLevel.empty())
            {
                l2r=!l2r;
                swap(currLevel,nextLevel);
            }
        }

    }


    int main(){
        struct node* root=new node(12);
        root->left=new node(9);
        root->right=new node(15);
        root->left->left=new node(5);
        root->left->right=new node(10);

        ZigZag(root);
      
        return 0;
    }
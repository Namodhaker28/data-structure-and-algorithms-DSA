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
    bool isIdentical(node *root1,node* root2 )
    {
        if(!root1 && !root2)
        return true;

        if(root1&&root2)
        {
            if(root1->data==root2->data)
            {
                bool left=isIdentical(root1->left,root2->left);
                bool right=isIdentical(root1->right,root2->right);

                if(left&&right)
                return true;
                else
                return false;
               
            }
          
        }

        return false;
    }


    int main(){
        struct node* root1=new node(12);
        root1->left=new node(9);
        root1->right=new node(15);
        root1->left->left=new node(5);
        root1->left->right=new node(10);

        struct node* root2=new node(12);
        root2->left=new node(9);
        root2->right=new node(15);
        root2->left->left=new node(5);
        root2->left->right=new node(10);

        if(isIdentical(root1,root2))
        cout<<"identical";
        else
        cout<<"different";
        return 0;
    }

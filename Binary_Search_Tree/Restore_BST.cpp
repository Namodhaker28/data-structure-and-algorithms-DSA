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
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }

    void calcPointers(node* root,node**first,node**last,node**mid,node**prev)
    {
        if(root==NULL)
        return ;

        calcPointers( root->left,first,last,mid,prev);

        if(*prev&&root->data<(*prev)->data)
        {
            if(!*first)
            {
                *first=*prev;
                *mid=root;
            }
            else
            {
                *last=root;
            }
        }
        *prev=root;
        calcPointers( root->right,first,last,mid,prev);
    }

    void restore(node* root)
    {
        node* first, *last,*mid,*prev;
        first=NULL;
        last=NULL;
        mid=NULL;
        prev=NULL;

        calcPointers(root,&first,&last,&mid,&prev);

        if(first&&last)
        {
            swap(&(first->data),&(last->data));
        }
        else
        {
            swap(&(first->data),&(mid->data));
        }


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
        struct node* root=new node(12);
        root->left=new node(5);
        root->right=new node(15);
        root->left->left=new node(9);
        root->left->right=new node(10);

        inorder(root);
        restore(root);
        cout<<endl;
        inorder(root);

        
        return 0;
    }
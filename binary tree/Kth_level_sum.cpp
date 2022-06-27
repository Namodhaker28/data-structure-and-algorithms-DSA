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

    void ltraversal(node * root,int k)
    {
        if(root==NULL)
        return ;

        queue<node*>q;
        q.push(root);
        q.push(NULL);

        int level=0;
        int sum=0;

        while(!q.empty())
        {
            node* nod=q.front();
            q.pop();
            

            if(nod!=NULL)
            {
                if(level==k)
                {
                    sum+=nod->data;
                }
                if(nod->left)
                q.push(nod->left);
                if(nod->right)
                q.push(nod->right);

            }
            else if(!q.empty())
            {
            q.push(NULL);
            level++;
            }

        }

        cout<<sum;
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

    ltraversal(root,2);
    return 0;
}
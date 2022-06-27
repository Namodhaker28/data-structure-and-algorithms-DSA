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

int srch(int inorder[],int start,int end, int curr)
{
    for(int j=start;j<end;j++)
    {
        if(inorder[j]==curr)
        return j;
    }

    return -1;
}

node* build(int preorder[],int inorder[],int start,int end)
{
    static int i=0;

    if(start>end)
    return NULL;
    
    int curr=preorder[i];
    i++;
    node* nod=new node(curr);

    if(start==end)
    return nod;

    int pos=srch(inorder,start,end,curr);
    nod->left=build(preorder,inorder,start,pos-1);
    nod->right=build(preorder,inorder,pos+1,end);


    return nod;

}

void inoder(struct node* root)
    {
        if(root==NULL)
        return ;

        
        inoder(root->left);
        cout<<root->data<<" ";
        inoder(root->right);
        
    }

int main()
{
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};

    node* root=build(preorder,inorder,0,(sizeof(inorder)/sizeof(inorder[0]))-1);

    inoder(root);

    return 0;
}
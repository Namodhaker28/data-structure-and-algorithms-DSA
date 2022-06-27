#include<bits/stdc++.h>
using namespace std;

void revers(int a[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        swap(a[i],a[n-1-i]);
    }
}

void print(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main (){

    int a[]={5,6,7,4,6,7,3,6,7,3};
    int n=sizeof(a)/sizeof(a[0]);
    revers(a,n);

    print(a,n);

    
    return 0;
}
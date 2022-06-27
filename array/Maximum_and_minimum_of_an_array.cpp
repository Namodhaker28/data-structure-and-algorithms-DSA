#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }

    int mini=a[0];
    int maxi=a[0];
    for (int i = 0; i < 10; i++)
    {
        maxi=max(a[i],maxi);
        mini=min(a[i],mini);
    }

    cout<<mini<<" "<<maxi<<endl;
    

    return 0;
}
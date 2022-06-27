
#include<bits\stdc++.h>
using namespace std ;

int main()
{
    vector<int>v(256,-1);
    int ans=0,start=-1;

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(v[s[i]]>start)
        start=v[s[i]];

        v[s[i]]=i;
        ans=max(ans,i-start);
    }

    cout<<ans;

    return 0;
}

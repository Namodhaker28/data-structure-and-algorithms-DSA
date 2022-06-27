#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    vector <int>v(n);
    for (auto &i:v)
    cin>>i;
    
    vector<int >ans;
    deque<int>q;
    
    for(int i=0;i<k;i++)
    {
        while(!q.empty() and v[q.back()]<v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);
    
    for(int i=k;i<n;i++)
    {
        if(q.front()==i-k)
        q.pop_front();
        
        while(!q.empty() and v[q.back()]<v[i])
        {
            q.pop_back();
        }
        
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }
    
    for(auto a:ans)
    cout<<a<<"  ";
    
    return 0;
}

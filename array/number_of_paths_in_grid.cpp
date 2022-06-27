#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int paths(int n,int m)
{
    if(n==1||m==1)
    return 1;

    return paths(m-1,n)+paths(m,n-1);
}


int main() {
cout<<paths(3,3);
	
}
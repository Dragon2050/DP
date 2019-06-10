#include<bits/stdc++.h>

using namespace std;

int coin_change(int s[],int m,int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m<=0 and n>=1)
        return 0;
    return coin_change(s,m,n-s[m-1])+coin_change(s,m-1,n);
}

int main()
{
    int s[3]={1,2,3};
    int n;
    cin>>n;
    int res=coin_change(s,3,n);
    cout<<res<<endl;
    return 0;
}

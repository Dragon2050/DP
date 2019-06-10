#include<bits/stdc++.h>

using namespace std;

int n,coin[100000],make,dp[1000][1000];

int fun(int coinnumber,int amount)
{
    if(coinnumber==n)
    {
        if(amount==make)
            return 1;
        else
            return 0;
    }
    if(dp[coinnumber][amount]!=-1)
        return dp[coinnumber][amount];
    int res1=0,res2=0;
    if(amount+coin[coinnumber]<=make)
    {
        res1=fun(coinnumber,amount+coin[coinnumber]);
    }
    res2=fun(coinnumber+1,amount);
    return dp[coinnumber][amount]=res1+res2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;///number of coin
    for(int i=0;i<n;i++)
    {
        cin>>coin[i]; ///value of each coin.
    }
    cin>>make;
    int res=fun(0,0);
    cout<<res<<endl;
    return 0;
}

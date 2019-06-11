#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define scin(x) scanf("%lld",&x)

lli dp[2005][2005],profit[2000005],val[2000005],w[2000005],knapsack_weight,items;

lli bottomup(void)
{
    for(int i=1;i<=items;i++)
    {
        for(int j=1;j<=knapsack_weight;j++)
        {
            if(w[i]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+profit[i]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[items][knapsack_weight];
}

int main()
{
    scin(knapsack_weight),scin(items);
    for(int i=1;i<=items;i++)
    {
        scin(w[i]),scin(profit[i]);
    }
    lli ans = bottomup();
    cout<<ans<<endl;
    return 0;
}

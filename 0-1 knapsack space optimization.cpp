#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define scin(x) scanf("%lld",&x)

lli dp[2][200005],profit[2000005],val[2000005],w[2000005],knapsack_weight,items;

lli bottomup(void)
{
    lli ans;
    for(int i=1; i<=items; i++)
    {
        for(int j=1; j<=knapsack_weight; j++)
        {
            if(i%2==1)
            {
                if(w[i]<=j)
                {
                    ans=dp[1][j]=max(dp[0][j],dp[0][j-w[i]]+profit[i]);
                }
                else
                {
                   ans= dp[1][j]=dp[0][j];
                }
            }
            else
            {
                if(w[i]<=j)
                {
                    ans=dp[0][j]=max(dp[1][j],dp[1][j-w[i]]+profit[i]);
                }
                else
                {
                    ans=dp[0][j]=dp[1][j];
                }
            }
        }
    }
    return ans;
}

int main()
{
    scin(knapsack_weight),scin(items);
    for(int i=1; i<=items; i++)
    {
        scin(w[i]),scin(profit[i]);
    }
    lli ans = bottomup();
    cout<<ans<<endl;
    return 0;
}

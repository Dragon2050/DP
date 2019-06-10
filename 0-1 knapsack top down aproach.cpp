#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define scin(x) scanf("%lld",&x)

lli dp[2005][2005],w[2000005],val[2000005];

lli knapsack(lli bag_size,lli items,lli n)
{
    lli ans;
    if(n>items || bag_size==0)
        return 0;
    if(dp[bag_size][n]!=0)
        return dp[bag_size][n];
    if(w[n]>bag_size)
        return dp[bag_size][n]=knapsack(bag_size,items,n+1);
    else
    {
        return dp[bag_size][n]=max(knapsack(bag_size,items,n+1),val[n]+knapsack(bag_size-w[n],items,n+1));
    }
}

int main()
{
    lli bag_size,items;
    scin(bag_size),scin(items);

    for(int i=1;i<=items;i++)
    {
        scin(w[i]),scin(val[i]);
    }

    lli ans=knapsack(bag_size,items,1);
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{
    lli n,totweight;
    cin>>n>>totweight;
    lli w[n+5],v[n+5],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
    lli dp[sum+5];
    for(int i=0;i<=sum;i++)
    {
        dp[i]=1000000000000000000;
    }
    ///cout<<dp[0]<<endl;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(lli j=sum;j>=0;j--)
        {
            if(j+v[i]<=sum)
            {
                dp[j+v[i]]=min(dp[j+v[i]],dp[j]+w[i]);
            }
        }
    }
    lli ans=0;
    for(int i=0;i<=sum;i++)
    {
        if(dp[i]<=totweight)
            ans=i;
    }
    cout<<ans;
    return 0;
}

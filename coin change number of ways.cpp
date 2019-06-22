#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{
    int n;
    cin>>n;
    lli coin[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    lli make;
    cin>>make;
    lli nways[make+5]={0};
    nways[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i],k=0;j<=make;j++,k++)
        {
            nways[j]=nways[j]+nways[k];
        }
    }
    for(int i=0;i<=make;i++)
    {
        cout<<i<<" "<<nways[i]<<endl;
    }
    return 0;
}

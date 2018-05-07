#include<bits/stdc++.h>

using namespace std;

int knapsack(int n,int m,int val[],int weight[])
{
    int k[n+1][m+1];
    ///k[][] IS THE TABLE FOR CALCULATING BENIFITS IN EVERY WEIGHT UPTO m..
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ///IF THERE IS NO ITEM OR NO BAG THEN THIS CONDITION WORK..
            if(i==0||j==0)
            {
                k[i][j]=0;
            }
            else if(weight[i-1]<=m)
            {
                k[i][j]=max(val[i-1]+k[i-1][j-weight[i-1]],k[i-1][j]);
            }
            else
                k[i][j]=k[i-1][j];
        }
    }
    return k[n][m];
}

int main()
{
    int n,m;
    ///Press the number of items..
    cin>>n;
    ///PRESS THE MAXIMUM WEIGHT..
    cin>>m;
    int val[n+1],weight[n+1];
    ///PRESS THE VALUE AND WEIGHT...
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>weight[i];
    }
    ///CALL THE 0-1 KNAPSACK FUNCTION...
    int res=knapsack(n,m,val,weight);
    ///PRINT THE MAXIMUM BENIFIT..
    cout<<res<<endl;
    return 0;
}

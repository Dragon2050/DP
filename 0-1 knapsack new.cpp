#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli knapsack_weight,items,profit[2005][2005],weight[2000005],values[2000005],track[2000005];

stack<lli> st;

int main()
{
    int i,w;
    scanf("%d %d",&knapsack_weight,&items);

    for(i=1;i<=items;i++)
    {
        scanf("%lld%lld",&weight[i],&values[i]);
    }

    for(i=0; i<=items; i++)
    {

        profit[i][0] = 0;//no weight is taken, so no profit so far

    }

    for(w=0; w<=knapsack_weight; w++)
    {

        profit[0][w] = 0;//no item is taken, so no profit so far.

    }



    for(i=1; i<=items; i++)
    {

        for(w=1; w<=knapsack_weight; w++)
        {

            if(weight[i]>w)
            {

                profit[i][w] = profit[i-1][w];

            }

            else
            {

                if(profit[i-1][w]>=profit[i-1][w-weight[i]]+values[i])
                {

                    profit[i][w] = profit[i-1][w];



                }

                else
                {

                    profit[i][w] = profit[i-1][w-weight[i]]+values[i];

                    track[profit[i][w]] = i;

                }

            }

        }

    }

    //track the taken values





    i = profit[items][knapsack_weight];

    int j = track[i];

    //for(j=track[knapsack_weight];j!=0;){



    while(j!=0)
    {

        //i = track[j];





        st.push(values[j]);

        i = i - values[j];

        j=track[i];

        //j = j-values[j];

    }
    cout<<endl<<endl;
    while(!st.empty())
    {

        printf("%lld ",st.top());

        st.pop();

    }
    cout<<endl;
    printf("sum:%lld\n",profit[items][knapsack_weight]);

    return 0;
}

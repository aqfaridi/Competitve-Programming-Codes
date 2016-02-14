#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int w[510],v[510];
int dp[10010];
int main()
{
    ios::sync_with_stdio(false);
    int t,W,E,F,n;
    cin>>t;
    while(t--)
    {
        memset(dp,31,sizeof(dp));
        cin>>E>>F;
        W = F-E;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>v[i]>>w[i];
       
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=W;j++)
                dp[j] = min(dp[j],v[i]+dp[j-w[i]]);

        if(dp[W]!=522133279)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
/*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(j-w[i] >=0)
                    dp[j] = max(v[i]+dp[j-w[i]] , dp[j]);
                cout<<dp[j]<<" ";
            }
            cout<<endl;
        }

        for(int i=1;i<=W;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i-w[j]>=0)
                    dp[i] = max(dp[i], v[j] + dp[i-w[j]]) ;
                cout<<dp[i]<<" ";
            }
            cout<<endl;
        }
*/
    }
    return 0;
}



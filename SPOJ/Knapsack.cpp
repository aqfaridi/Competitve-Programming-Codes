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
int w[2010],v[2010];
int dp[2010][2010];
int main()
{
    int W,n;
    cin>>W>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
   /* 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j-w[i] >=0 && (v[i] + dp[i-1][j-w[i]] > dp[i-1][j]))
                dp[i][j] = v[i] + dp[i-1][j-w[i]];
            else 
                dp[i][j] = dp[i-1][j];

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }    
    
    cout<<endl;
    memset(dp,0,sizeof dp);
    */
    for(int i=1;i<=W;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-w[j] >= 0 && (v[j] + dp[i-w[j]][j-1] > dp[i][j-1]))
                dp[i][j] = v[j] + dp[i-w[j]][j-1];
            else
                dp[i][j] = dp[i][j-1];

       //     cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[W][n]<<endl;
    return 0;
}



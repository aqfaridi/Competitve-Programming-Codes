#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 10100
#define MOD 1000000007    
int d[MAX],dp[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>m;
        for(int i=0;i<m;i++)
            cin>>d[i];
        sort(d,d+m);
        dp[0]=0;
        for(int j=1;j<=n;j++)
        {
            dp[j] = -INT_MAX;
            for(int i=0;i<m;i++)
                if(j>=d[i])
                    dp[j] = max(dp[j],1+dp[j-d[i]]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

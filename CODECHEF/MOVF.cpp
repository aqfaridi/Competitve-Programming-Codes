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

#define MAX 100010
#define MOD 1000000007    
int dp[550][1100],arr[550];
char str[1100];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k;
    char ch;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof dp);
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            scanf("%[^\n]s",str);
            ch = getchar();
            cin>>arr[i];
        }
        sort(arr,arr+n+1);
        for(int i=1;i<=n;i++)
        {
            dp[i][arr[i]] = 1;
            for(int j=0;j<=k;j++) //not taking arr[i]
                dp[i][j] += dp[i-1][j];
            for(int j=0;j<=k;j++)
                if(j-arr[i] >= 0)
                    dp[i][j] += dp[i-1][j-arr[i]];
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}

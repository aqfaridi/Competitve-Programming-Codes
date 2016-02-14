#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL dp[1000];
void sieve()
{
    dp[1]=0;
    dp[2]=dp[3] = 1;
    for(int i=4;i<=999;i++)
        dp[i] = (1LL<<(i-3)) + dp[i-2];
}
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<dp[n]<<endl;
    }
}

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
unsigned long long dp[60];
void precalc()
{
    dp[1] = 3,dp[2] = 7;
    for(int i=3;i<=50;i++)
        dp[i] = 2*dp[i-1] + dp[i-2];
}
int main()
{
    precalc();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%llu\n",dp[n]);        
    }
    return 0;
}

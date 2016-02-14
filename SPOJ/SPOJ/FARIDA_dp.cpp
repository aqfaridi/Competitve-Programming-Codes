#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
int arr[MAX];
long long dp[MAX];
int main()
{
    int t,n,cases=0;
    long long sum;
   // ios::sync_with_stdio(false);
    scanf("%d",&t);    
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        for(int i=0;i<n;i++)        
            scanf("%d",&arr[i]);

        /*** base case***/
        dp[0] = arr[0]; // if only one element present
        dp[1] = max(arr[0],arr[1]);  //if only two element present in series
        
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-2]+arr[i],dp[i-1]); //ith element choosen or not
        
        printf("Case %d: %lld\n",cases,dp[n-1]);
        
    }
    return 0;
}


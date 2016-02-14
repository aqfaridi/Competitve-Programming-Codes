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
LL dp[100];
void make_dp()
{
    dp[1] = 3;
    dp[2] = 11;
    for(int i=3;i<=25;i++)
        dp[i] = 3*dp[i-1] + 2*dp[i-2];
}
int main()
{
    make_dp();
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
            cout<<dp[n/4]<<endl;            
    }
    return 0;
}

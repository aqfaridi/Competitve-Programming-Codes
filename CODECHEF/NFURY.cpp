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
int dp[1025];
void precalc()
{
    int minn;
    for(int i=1;i<=32;i++)
        dp[i*i] = 1;
    for(int i=1;i<=1000;i++)
    {
        if(dp[i])   continue;
        minn = 100000;
        for(int j=1;j<=i/2;j++)
        {
            if((dp[j]+dp[i-j])<minn)
                minn = dp[j]+dp[i-j];
        }
        dp[i] = minn;
    }
}
int main()
{
    precalc();
    /*
    for(int i=0;i<=1000;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    */
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl; 
    }
    return 0;
}

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
int dp[110][110];
int main()
{
    int n,k;
    cin>>n>>k;
    int j=n-1;
    for(int i=0;i<n;i++)
    {
        dp[i][j] = k;
        j--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    int t,k,l,min_updown,min_diag;
    //scanf("%d",&t);
    t = 1;
    while(t--)
    {
        scanf("%d %d",&k,&l);
        int dp[k+1][l+1];
        char a[k+1],b[l+1];
        for(int j=0;j<=l;j++)
            dp[0][j] = j;
        
        scanf("%s",a+1);
        scanf("%s",b+1);
        
        for(int i=1;i<=k;i++)
        {
            dp[i%3][0] = i;
            for(int j=1;j<=l;j++)
            {
                min_updown = min(dp[i%3][j-1]+1,dp[(i-1)%3][j]+1);
                min_diag = (a[i]==b[j])?(dp[(i-1)%3][j-1]):(dp[(i-1)%3][j-1]+1);
                if(i>=2 && j>=2 && (a[i] == b[j-1]) && (a[i-1] == b[j]))
                    min_diag = min(min_diag,dp[(i-2)%3][j-2]+1);
                dp[i%3][j] = min(min_updown,min_diag);
            }
        }
        /**
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<=l;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        **/
        printf("%d\n",dp[k%3][l]);
    }
    return 0;
}


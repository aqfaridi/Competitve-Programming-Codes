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
LL dp[50];
void precompute()
{
    dp[1] = 3;
    dp[2] = 9;
    for(int i=3;i<=50;i++)
        dp[i] = 2*dp[i-1] + dp[i-2];
}
int main()
{
    int t,n;
    precompute();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cout<<dp[n]<<endl;
    }
    return 0;
}


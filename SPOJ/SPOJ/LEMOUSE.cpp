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
#define MAX 110
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
char arr[MAX][MAX];
int dp[MAX][MAX];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",arr[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }

    }
    return 0;
}


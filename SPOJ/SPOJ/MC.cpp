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
char str1[1010],str2[1010];
int LCS[1010][1010];
int LCSeq(int m, int n)
{
    for(int i=0;i<=m;i++)
        LCS[i][0] = 0;
    for(int j=0;j<=n;j++)
        LCS[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i] == str2[j])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    return LCS[m][n];
}
int main()
{
    int t,m,n,lcs;
    while(1)
    {
        scanf("%s",str1+1);
        if(str1[1]=='#')
            break;
        scanf("%s",str2+1);
        m = strlen(str1+1);
        n = strlen(str2+1);
        lcs = LCSeq(m,n);
        cout << 15*(m-lcs) + 30*(n-lcs) << endl;
    }
    return 0;
}


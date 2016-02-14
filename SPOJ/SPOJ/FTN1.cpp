#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    uLL t,n,res;
    scanf("%llu",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%llu",&n);
        res = 2*n - 1;
        printf("Case %d: %llu\n",i,res);
        if(i==t)
            printf("\n");
    }
    return 0;
}


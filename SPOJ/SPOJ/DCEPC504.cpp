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
LL func(LL n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if((n&1))
        return 1-func(n/2);
    else
        return func(n/2);
}
int main()
{
    LL t,n,k,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        ans = func(k-1);      
        if(ans == 0)
            printf("Male\n");
        else
            printf("Female\n");
    }
    return 0;
}


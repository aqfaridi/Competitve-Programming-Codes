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
LL g_josephus(LL n,LL k)
{
    if(n==1)
        return 0;//starting index 0
    return (g_josephus(n-1,k) + k)%n;
}
LL f_josephus(LL n,LL k)
{
    if(n==1)
        return 1;
    return ( (f_josephus(n-1,k) + (k-1))%n + 1);
}
LL iterative(LL n,LL k)
{
    LL r=0;
    LL i=2;
    while(i<=n)
    {
        r = (r+k)%i;
        i++;
    }
    return (r+1);
}
int main()
{
    LL t,n,k;
    //scanf("%lld",&t);
    while(1)
    {
        scanf("%lld %lld",&n,&k);
        if(n==0 && k==0)
            break;
        printf("%lld %lld %lld\n",n,k,iterative(n,k));        
    }
    return 0;
}


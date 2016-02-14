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
// for k=2
// f(n) = 2*l + 1;  and l = n - (2^m)  and m = floor(log2(n))
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result ;
}
int main()
{
    LL t,n,k,fn,l,m;
    string str;
    //scanf("%lld",&t);
    while(1)
    {
        cin>>str;
        n = (str[0]-'0')*10 + (str[1]-'0') ;
        for(int i=0;i < str[3]-'0';i++)
            n *= 10;
        k = 2;
        if(n==0)
            break;
        m  = (LL)floor(log2(n));
        l = n - expo(2,m);
        fn = 2*l + 1;
        printf("%lld\n",fn);        
    }
    return 0;
}


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
pair<int,pair<int,int> > extendedEuclid(long long a,long long b)
{
    //ax + by = gcd(a,b)
    //r(i) = r(i-2) - q(i)*r(i-1)
    long long xLast = 1,yLast = 0,q,r,m,n;
    long long x = 0,y = 1;
    while(b!=0)
    {
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;
        xLast = x ; yLast = y;
        x = m ; y = n;
        a = b; b = r;
    }
    return make_pair(a,make_pair(xLast,yLast));
}
long long modInverse(long long a,long long m)
{
    return (extendedEuclid(a,m).second.first + m)%m; // taking care of -ve
}
int main()
{
    LL t,a,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&m);
        cout<<modInverse(a,m)<<endl;
        
    }
    return 0;
}


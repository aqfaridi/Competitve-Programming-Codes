#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long expo(long long a,long long n,long long mod=29)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result * a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return result % mod;
}


pair<int, pair<int, int> > extendedEuclid(int a, int b)
{
    int xLast = 1, yLast = 0;
    int x = 0, y = 1;
    
    int q, r, m, n;
    while(b != 0) 
    {
        q = a / b;
        r = a % b;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        a = b, b = r;
    }
    return make_pair(a, make_pair(xLast, yLast));
}
int modInverse(int a, int m=29) 
{
    return (extendedEuclid(a,m).second.first + m) % m;
}
int main()
{
    int x;
    // 2004 = 2*2*3*167
    int mod = 29;
    while(scanf("%d",&x) && x)
    {
        cout<<( ( (expo(2,2*x+1)%mod - 1%mod +mod ) * ((expo(3,x+1)%mod - 1%mod + mod)*modInverse(2,mod))%mod )%mod * ((expo(167,x+1)%mod -1%mod + mod) * modInverse(166,mod))%mod )%mod <<endl ;

    }
    return 0;
}


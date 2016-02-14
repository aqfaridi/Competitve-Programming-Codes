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
LL f[64];
void powerof2()
{
    //f(0) = 1;
    //f(n) = (1<<n) + (f(0)+f(1)+f(2)+..........+f(n-1))
    f[0] = 1;
    for(int n=1;n<64;n++) // n is power of 2
    {
        f[n] = (1<<n);
        for(int i=0;i<n;i++)
            f[n] += f[i];
    }
}
LL expo(LL n)
{
    LL k=0,result = 0LL;
    while(n>0)
    {
        if((n&1))
            result += f[k];
        k++;
        n >>= 1;
    }
    return result;
}
int main()
{
    LL a,b;
  
    powerof2();
    //for(int i=0;i<20;i++)
      //          cout<<f[i]<<" ";
    while(scanf("%lld %lld",&a,&b) != EOF)
    {
        printf("%lld\n",expo(b)-expo(a-1));         
    }
    return 0;
}


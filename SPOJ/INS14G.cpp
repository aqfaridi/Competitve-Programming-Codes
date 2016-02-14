#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define MAX 1000010
using namespace std;
long long fib[MAX];
void precalc()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<MAX;i++)
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
}
int main()
{
    precalc();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",fib[n]);
    }
    return 0;
}



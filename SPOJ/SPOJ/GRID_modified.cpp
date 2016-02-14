#include <iostream>
#include <cstdio>
using namespace std;
long long nCr[2001];
long long expo(long long a,long long n,long long mod)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result = (result*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return result%mod;
}
void calc_nCr(long long n,long long r,long long mod)
{
    nCr[0] = 1;
    for(int i=1;i<=r;i++)
    {
        nCr[i] = ((nCr[i-1] * (n-i+1))/i)%mod;
    }

}
int main()
{
    int t,m,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&m,&n,&k);
        calc_nCr(m+n,n,k);
        printf("%lld\n",nCr[n]);
    }

    return 0;
}

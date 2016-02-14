#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
long long sum[MAX];
long long  primeFactorize(long long n)
{
    double pro = n;
    for(int d=2;d*d<=n;d++)
    {
        if(n%d == 0)
        {
            //d is the divisor of n
            while(n%d==0)
                n/=d;
            pro *= (1.0-1.0/d);
        }
    }
    if(n>1)
        pro *= (1.0 - 1.0/n);

    return (long long)pro;
}
void reqSum()
{
    for(int i=1;i<MAX;i++)
    {
        // considering all divisors
        for(int j=i;j<MAX;j+=i)
            sum[j] = sum[j] + i*primeFactorize(i); // i is the divisor of j
    }

}
int main()
{
    int t;
    long long n,lcmSum;
    scanf("%d",&t);
    reqSum();
    //cout<<primeFactorize(5)<<endl;
    while(t--)
    {
        scanf("%lld",&n);
        lcmSum = n*(1+sum[n])/2;
        printf("%lld\n",lcmSum);
    }
    return 0;
}


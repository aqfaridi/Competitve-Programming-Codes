#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
long long etf[MAX];
long long sum[MAX]; 
void etfSieve()
{
    for(int i=1;i<MAX;i++)
        etf[i] = i;
    for(int i=2;i<MAX;i++)
    {
        if(etf[i] == i) // restricting distinct prime factors
        {
            etf[i] = i-1;
            for(int j=2*i;j<MAX;j+=i) // 2*i =>dont modify etf of primenumbers
            {
                etf[j] = etf[j] - etf[j]/i;  //(n-n/p)
            }
        }
        

    }
}
void reqSum()
{
    for(int i=1;i<MAX;i++)
    {
        // considering all divisors
        for(int j=i;j<MAX;j+=i)
            sum[j] = sum[j] + i*etf[i]; // i is the divisor of j
    }

}
int main()
{
    int t;
    long long n,lcmSum;
    scanf("%d",&t);
    etfSieve();
    reqSum();
    while(t--)
    {
        scanf("%lld",&n);
        lcmSum = n*(1+sum[n])/2;
        printf("%lld\n",lcmSum);
    }
    return 0;
}


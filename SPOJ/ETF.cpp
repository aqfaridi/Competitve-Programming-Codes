#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
long long int etf[MAX];
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
int main()
{
    int t,n;
    scanf("%d",&t);
    etfSieve();
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",etf[n]);
    }
    return 0;
}


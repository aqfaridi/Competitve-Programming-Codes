#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
double Nr1[MAX],Nr2[MAX],Dr[MAX];
double nCr1(long long n,long long r)
{
    Nr1[0] = 1.0;
    for(int i=1;i<=r;i++)
        Nr1[i] = (Nr1[i-1]*(n-i+1))/i;    
}
double nCr2(long long n,long long r)
{
    Nr2[0] = 1.0;
    for(int i=1;i<=r;i++)
        Nr2[i] = (Nr2[i-1]*(n-i+1))/i;
}
double nCr3(long long n,long r)
{
    Dr[0] = 1.0;
    for(int i=1;i<=r;i++)
        Dr[i] = (Dr[i-1]*(n-i+1))/i;
}
int main()
{
    int t;
    long long S,N,M,K;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&S,&N,&M,&K);
        if(S==N)
        {
            printf("%.6f\n",1.000000);
            continue;
        }
        if(N<K+1)
        {
            printf("%.6f\n",0.000000);
            continue;
        }
        nCr3(S-1,N-1);
        nCr1(M-1,K);
        nCr2(S-M,N-1);
        double a = 1.0;
        a = a/Dr[N-1];
        double sum = 0.0;
        for(int i=0;i<K;i++)
            sum += (Nr1[i]*Nr2[N-1-i]);
        
        a *= sum;
        a = 1-a;
        printf("%.6lf\n",a);
    }    
    return 0;
}


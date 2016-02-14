#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
long long nCr[MAX];
long long expo(long long a,long long n)
{
    long long result = 1LL;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
int main()
{
    int n,k,x,cases=0;
    long long eval,power;
    while(1)
    {
        cases++;
        scanf("%d",&n);
        if(n==-1) 
            break;
        for(int i=0;i<=n;i++)
            scanf("%lld",&nCr[i]);
        scanf("%d",&k);
        printf("Case %d:\n",case,casess);
        for(int i=0;i<k;i++)
        {
            eval = 0LL;
            scanf("%d",&x);
            if(x==0)
            {
                printf("%lld\n",nCr[n]);
                continue;
            }
            power = expo(x,n);
            for(int j=0;j<=n;j++)
            {               
                eval += nCr[j]*(power);
                power /= x;
            }
            printf("%lld\n",eval);
        }
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,num;
    long long result ;
    ios::sync_with_stdio(false);
    int fact[16];
    fact[0] = 1;
    for(int i=1;i<=15;i++)
        fact[i] = fact[i-1] * i;
    while(scanf("%d %d",&n,&k) != EOF)
    {
        result = fact[n];
        for(int i=0;i<k;i++)
        {
            scanf("%d",&num);
            result = result / fact[num];
        }
        printf("%lld\n",result);
    }
    return 0;
}


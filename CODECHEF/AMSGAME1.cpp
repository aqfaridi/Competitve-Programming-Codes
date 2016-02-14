#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
typedef unsigned long long int LL;
using namespace std;
LL input[MAX];
LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int t;
    LL n,g;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%llu",&n);
        for(int i=0;i<n;i++)
            scanf("%llu",&input[i]);
       
        g = gcd(input[0],input[1]);
        for(int i=2;i<n;i++)
        {
            g = gcd(g,input[i]);
        }

        printf("%llu\n",g);
    }
    return 0;
}


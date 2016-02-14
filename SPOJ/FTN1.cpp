#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    long long n,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",cases,2*n-1);
    }
    return 0;
}


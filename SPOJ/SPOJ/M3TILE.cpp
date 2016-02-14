#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 31
using namespace std;
long long a[MAX];
void dp()
{
    a[0] = 1;
    a[1] = 0;
    a[2] = 3;
    for(int i=3;i<MAX;i++)
    {
        if((i&1))
            a[i] = 0 ;
        else
            a[i] = 4*a[i-2] - a[i-4] ;
    }
}
int main()
{
    int n;
    dp();
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        printf("%lld\n",a[n]);

    }
    return 0;
}


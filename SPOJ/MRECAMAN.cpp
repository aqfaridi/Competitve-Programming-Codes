#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 500010
#define NumLim 1000000
using namespace std;
long long  arr[MAX],sieve[NumLim];
void alter_sieve()
{   
    long long m;
    for(int i=1;i<MAX;i++)
    {
        m=i;
        if( (arr[m-1] - m > 0) && (sieve[arr[m-1] - m] != 1) )
            arr[m] = arr[m-1] - m;
        else
            arr[m] = arr[m-1] + m; 
        
        sieve[arr[m]] = 1;
    }

}

int main()
{
    alter_sieve();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",arr[n]);
    }
    return 0;
}


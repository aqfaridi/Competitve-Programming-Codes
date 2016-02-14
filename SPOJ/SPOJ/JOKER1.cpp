#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long maxval[70];
int main()
{
    int t,n;
    bool b;
    long long res;
    scanf("%d",&t);
    while(t--)
    {
        b=false;
        res = 1LL;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&maxval[i]);
        }
        sort(maxval,maxval+n);
        for(int i=n-1;i>=0;i--)
        {
            maxval[i] -= i;
            if(maxval[i]<=0)
            {
                b = true;
                break;
            }
            res = (res * maxval[i])%MOD;
        }
        if(b)
            printf("0\n");
        else
            printf("%lld\n",res);
    }       
    printf("KILL BATMAN\n");
    return 0;
}


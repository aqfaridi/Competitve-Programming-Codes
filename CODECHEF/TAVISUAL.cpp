#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long t,N,C,Q,L,U,diff;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&N,&C,&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%lld %lld",&L,&U);
            if(C >=L && C <= U)
            {
                diff=C-L;
                C=U-diff;
            }

        }    
        printf("%lld\n",C);
    }
    return 0;
}


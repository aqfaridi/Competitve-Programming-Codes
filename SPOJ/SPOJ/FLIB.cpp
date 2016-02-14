#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
void multiply(long long a[][2],long long b[][2])
{
    long long C[2][2]={0};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                C[i][j] += (a[i][k]*b[k][j]) ;
                C[i][j] %= MOD;
            }
        }
    }
    //copying
    memcpy(a,C,sizeof(C));
            
}
long long result[2][2],a[2][2],unity[2][2]={{1,0},{0,1}},M[2][2]={{1,1},{1,0}};
void expo(long long n)
{
    memcpy(result,unity,sizeof(unity));
    memcpy(a,M,sizeof(M));
    while(n>0)
    {
        if((n&1))
            multiply(result,a);
        multiply(a,a);
        n >>= 1;
    }
}
int main()
{
    long long t,n;
    long long Gn;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        expo(n<<1);
        printf("%lld\n",(result[0][0]*result[0][1])%MOD);

    }
    return 0;
}


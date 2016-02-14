#include <iostream>
#include <cstdio>
#define MOD 123456789
using namespace std;

void multiplyy(long long a[][2] , long long b[][2])
{
    long long c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%MOD)%MOD;
            }
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
}
void expo(long long M[][2],long long n)
{
    long long result[2][2]={{1,0},{0,1}};
    while(n>0)
    {
        if((n&1))
            multiplyy(result,M);
        multiplyy(M,M);
        n >>= 1;
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            M[i][j]=result[i][j];
}
long long fibo(long long n)
{
    long long M[2][2]={{1,1,},{1,0}};
    expo(M,n-1);

    return M[0][0] % MOD ;
}
int main()
{
  
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        //cout<<fibo(n);
        if(n==1)
        {
            printf("3\n");
            continue;
        }
        n = n-1;
        printf("%lld\n",(3 + (fibo(n) + (4 * n)%MOD )%MOD)%MOD);

    }
    return 0;
}

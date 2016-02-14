#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long LL;
void multiply(LL a[][2],LL b[][2])
{
    LL C[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            C[i][j] = 0;
            for(int k=0;k<2;k++)
                C[i][j] = (C[i][j] + a[i][k]*b[k][j])%MOD;
        }
    }
    /** 
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j] = C[i][j];
    **/
    memcpy(a,C,sizeof C);
}
void expo(LL a[][2],LL n)
{
    LL result[2][2] = {{1,0},{0,1}};
    while(n)
    {
        if((n&1))
            multiply(result,a);
        multiply(a,a);
        n>>=1;
    }
    /**
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j] = result[i][j];
    **/
    memcpy(a,result,sizeof result);
}
LL fibo(LL n)
{
    LL M[2][2] = {{1,1},{1,0}};
    expo(M,n-1);
    return (M[0][0] % MOD);
}
int main()
{
    int t;
    LL n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        //cout<<fibo(n+1)<<endl;
        //cout<<fibo(n+2)<<endl;
        //cout<<fibo(n+1) * fibo(n+2)<<endl;
        printf("$%lld\n",((fibo(n+1)*fibo(n+2))%MOD -1%MOD +MOD)%MOD);
    }
    return 0;
}


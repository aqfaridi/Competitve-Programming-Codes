#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
int MOD;
using namespace std;
void multiply(long long int a[][2],long long int b[][2])
{
    long long int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }

        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=c[i][j];
        }
    }


}
void  power(long long int a[][2],long long int n)
{
    long long int result[2][2]={{1,0},{0,1}}; //unity matrix
    while(n>0)
    {
        if((n&1))
            multiply(result,a);

        multiply(a,a);
        n/=2;
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=result[i][j];
}

long long int fibo(long long int n)
{
    if(n==0)
        return 0;
    long long int obj_matrix[2][2]={{1,1},{1,0}};
    power(obj_matrix,n-1);

    return obj_matrix[0][0]%MOD;

}
int main()
{
    long long int t,n,m,a,b,g;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        MOD = m;
        a = fibo(2*n-1)%m;
        b = fibo(2*n)%m;
        g = 1;//__gcd(a,b);
        cout<<a/g<<"/"<<b/g<<endl;

    }
    return 0;
}


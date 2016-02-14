#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
void multiply(long long int a[][2],long long int b[][2],long long int m)
{
    long long int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]= (c[i][j]+(a[i][k]*b[k][j])%m)%m;
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
void  power(long long int a[][2],long long int n,long long int m)
{
    long long int result[2][2]={{1,0},{0,1}}; //unity matrix
    while(n>0)
    {
        if((n&1))
            multiply(result,a,m);

        multiply(a,a,m);
        n>>=1;
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=result[i][j];
}

long long fibo(long long int obj_matrix[][2],long long int n,long long int m)
{
   power(obj_matrix,n,m);
}
int main()
{
    long long int t,a,d,r,m,n;
    scanf("%lld",&t);
    while(t--)
    {

        scanf("%lld %lld %lld",&a,&d,&r);
        scanf("%lld %lld",&n,&m);

            long long int obj_matrix[2][2]={{r,1},{0,1}};
            if(n==1)
            {
                printf("%lld\n",a);
                continue;
            }
            else if(n==2)
            {
                printf("%lld\n",a+d);
                continue;
            }

            else if((n&1))
            {
                fibo(obj_matrix,n/2,m);
                printf("%lld\n",((a*obj_matrix[0][0])%m  + ((d*r)%m*obj_matrix[0][1])%m)%m);
            }
            else
            {
                fibo(obj_matrix,(n/2)-1,m);
                printf("%lld\n",(((a%m+d%m)%m * obj_matrix[0][0])%m  + (d*obj_matrix[0][1])%m)%m);
            }

    }
    return 0;
}


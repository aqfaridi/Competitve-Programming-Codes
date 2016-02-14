#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MOD 1000000007
#define phi 1.61803398874989484820458683436563811772030917980576
#include <algorithm>
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
    int t;
    long long int n,fibo_n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
	/***
	if(n==1000000000)
		fibo_n = (fibo(n-1) + fibo(n-2))%MOD;
	else
		fibo_n = fibo(n);
	cout<<fibo_n;
	***/        
	printf("%lld\n",((fibo(n)*2)%MOD + fibo(n-1))%MOD ); 
    }
    return 0;
}


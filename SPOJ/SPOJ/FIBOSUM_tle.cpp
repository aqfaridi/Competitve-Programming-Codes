#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std;
int fibo(int n)
{
    if(n==0)
                return 0;
    if(n==1)
                return 1;
    return (fibo(n-1)+fibo(n-2));
} 
int main()
{
    long long int n,m,s;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%lld%lld",&n,&m);
        for(long long int i=n;i<=m;i++)
        {
            s+=(fibo(i)%MOD);
        }
        printf("%lld\n",s);
    }
     
    return 0;
}


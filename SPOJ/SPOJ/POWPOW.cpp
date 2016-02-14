#include <iostream>
#define MOD 1000000007
#define phi 500000002 
#define MAX 100010
#include <cstdio>
using namespace std;
long long int arr[2*MAX+1];
long long int expo(long long a,long long n,long long m)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return result%MOD;
}
int main()
{
    long long  exp,t,n,a,b;
    arr[1]=1,arr[0]=1;
    long long factNr,factDr;
    for(int i=2;i<2*MAX;i++)
        arr[i]=(arr[i-1]*i)%(MOD-1);
    scanf("%lld",&t);
    while(t--)
    {

        scanf("%lld %lld %lld",&a,&b,&n);
        factNr=arr[2*n];
        factDr=arr[n];
        factDr = (factDr*factDr)%(MOD-1);
        factDr = expo(factDr,phi-1,MOD-1);
        exp = (factNr*factDr)%(MOD-1);
        exp = expo(exp,b,MOD - 1); // mod by phi i.e mod -1  
        n = expo(a,exp,MOD);
        printf("%lld\n",n);
    }
    return 0;
}



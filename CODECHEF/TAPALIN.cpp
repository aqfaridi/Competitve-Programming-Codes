#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long expo(long long a,long long n,long long mod)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
        {
            result = (result*a)%MOD;
        }
        a = (a*a)%MOD;
        n /=2;
    }
    return result;

}
int main()
{
    int t;
    long long n,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("26\n");
            continue;}
        if(n==2)
        {
            printf("52\n");
            continue;
        }
        if((n&1))
        {
            a=((n*n-1)%MOD + (2*((n-1)*(n-3)))%MOD + ((n-3)*(n-5))%MOD);
            //a = (a*25)%MOD;
            a = (a * expo(8,MOD-2,MOD))%MOD;
            //cout<<a<<endl;
            a= (a*25)%MOD;
            a = (a + (n))%MOD;
            a = (a*26)%MOD;
            printf("%lld\n",a);
            continue;
        }
        else
        {
            a=( (2*n*(n-2))%MOD + (2*(n-2)*(n-4))%MOD);
            a= (a*expo(8,MOD-2,MOD))%MOD;
            a= (a*25)%MOD;
            a = (a+ (n))%MOD;
            a = (a*26)%MOD;
            printf("%lld\n",a);
            continue;
                    
        }
    }
    return 0;
}


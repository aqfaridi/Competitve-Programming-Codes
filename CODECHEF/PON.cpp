#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
long long mulmod(long long a,long long b,long long m)
{
    long long result = 0 ;
    while(b>0)
    {
        if((b&1))
            result = (result + a)%m;
        
        a = (2*a)%m;
        b >>= 1; 
    }
    return result%m;
}
long long modulo(long long a,long long n,long long m)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = mulmod(result,a,m);
        
        a = mulmod(a,a,m);
        n>>=1;
    }
    return result%m;
}
bool miller_rabin(long long n,int iteration)
{
    if(n<2)
        return false;
    if(n!=2 && n%2==0)
        return false;
    long long d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<iteration;i++)
    {
        long long a = (rand() % (n-1) + 1); //a: 1 to n-1 
        long long temp = d;   // for while stopping condition
        long long mod = modulo(a,d,n);
        while(mod!=1 && mod!=(n-1) && temp!=(n-1))
        {
            mod = mulmod(mod,mod,n); // squaring mod
            temp *= 2;
         }
        if(mod!=(n-1) && temp%2==0) // at intermediate step check for composite 
            return false;
    }
    return true;

}
int main()
{
    //checking whether n is prime or not
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(miller_rabin(n,2))
            printf("YES");
        else 
            printf("NO");

        printf("\n");
    }
    
    return 0;
}


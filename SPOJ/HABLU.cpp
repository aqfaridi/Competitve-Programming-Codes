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
namespace sieve
{
    #define MAX 1000010
    #define LIM 1000
    #define PRM 78500
    typedef long long LL;
    unsigned flag[MAX >> 6];
    LL primes[PRM];
    #define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
    #define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
    void make_sieve()
    {
        unsigned i,j,k;
        isc(1);
        for(i=3;i<=LIM;i+=2)
        {
            if(!ifc(i))
                for(j=i*i,k=(i<<1);j<MAX;j+=k)
                    isc(j);
        }
        primes[0] = 2;
        for(i=3,k=1;i<MAX;i+=2)
            if(!ifc(i))
                primes[k++] = i;
        //cout<<primes[k-1]<<endl;
        /*
        for(int i=0;i<100;i++)
            cout<<primes[i]<<" ";
        cout<<k<<endl;
        */
    }
}
using namespace sieve;
int main()
{
    make_sieve();
    int t;
    bool one;
    long long n,k,var,pro,cnt,N,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        N = n;
        one = false;
        pro = 1;
        if(miller_rabin(n,10))
        {
            for(int i=0;i<k;i++)
            {
                scanf("%lld",&var);
                if(var == 1)
                    one = true;
            }
            if(one)
                printf("0\n");
            else
                printf("1\n");
        }
        else
        { 
            for(int i=0;i<k;i++)
            {
                scanf("%lld",&var);
                if(var == 1)
                {
                    one = true;
                    continue;
                }
                while(n%var == 0)
                    n /= var;        
            }
            p = n;
            if(one)
            {
                printf("0\n");
                continue;
            }
            if(N == 1)
                printf("0\n");
            else
            {
               for(int i=0;primes[i]*primes[i]<=n;i++)
               {
                    if(n%primes[i] == 0)
                    {
                        cnt = 0;
                        while(n % primes[i] == 0)
                        {
                            cnt++;
                            n/=primes[i];
                        }
                        pro *= (cnt+1);
                    }
               }
               if(n>1)
                   pro *= 2;
               if(N != p)
                   printf("%lld\n",pro);
               else
                   printf("%lld\n",pro - 1);
            }
        }

    }
    
    return 0;
}

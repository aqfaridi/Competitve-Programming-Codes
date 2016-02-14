#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
long long expo(long long a,long long n,long long mod)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result * a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return result % mod;
}
pair<long long, pair<long long, long long > > extendedEuclid(long long a, long long  b)
{
    long long  xLast = 0, yLast = 1;
    long long x = 0,y = 1 ;
    long long q, r, m, n;
    while(b != 0) 
    {
        q = a / b;
        r = a % b;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        a = b, b = r;
    }
    cout<<a<<endl;
    return make_pair(a, make_pair(xLast, yLast));
}
int modInverse(long long  a, long long m) 
{
    return (extendedEuclid(a,m).second.first + m) % m;
}


int main()
{
    int t;
    long long a,d,r,n,mod,p,fterm,sterm;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&d,&r);
        scanf("%lld %lld",&n,&mod);
        
        if(r==0)
        {
            if(n==1)
            { 
                printf("%lld\n",a%mod);
                continue;
            }
            if(n==2)
            {
                printf("%lld\n",(a%mod+d%mod)%mod);
                continue;
            }

            if((n&1))
                printf("0\n");
            else
                printf("%lld\n",d%mod);
                        
        }       
        if(r==1)
        {
            if(n==1)
            {
                printf("%lld\n",a%mod);
                continue;
            }
            if((n&1))
            {
                n = n-1;
                n >>= 1;
                printf("%lld\n",(a%mod + (n*d)%mod)%mod);
            }
            else
            {
                n >>= 1;
                printf("%lld\n",(a%mod + (n*d)%mod)%mod);
            }

        }
        else
        {
            if((n&1)) //odd n
            {
                if(n==1)
                {
                    printf("%lld\n",a%mod);
                    continue;
                }
                p = (n-3)/2 + 1;
                long long exp = expo(r,p,mod);
                fterm = (a*exp)%mod;

                sterm = ((d*r*((exp%mod - 1%mod + mod)%mod))%mod *(modInverse(r-1,mod)))%mod; 

                printf("%lld\n",(fterm + sterm)%mod);
            }
            else
            {   
                if(n==2)
                {
                    printf("%lld\n",(a+d)%mod);
                    continue;
                }
                n = n-1;  
                p = (n-3)/2 + 1;
                long long exp = expo(r,p+1,mod);
                long long exp1 = expo(r,p,mod);
                fterm = (a*exp1)%mod;
                
                sterm = ((d*((exp%mod - 1%mod + mod)%mod))%mod *(modInverse(r-1,mod)))%mod; 

                printf("%lld\n",(fterm + sterm)%mod);

            }
        }
    }
    return 0;
}


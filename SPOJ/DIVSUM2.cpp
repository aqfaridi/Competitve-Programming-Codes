#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
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

long long expo(long long a,long long n)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
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
long long gcd(long long a,long long b)
{
        if(b==0)
                return a;
        else
                return gcd(b,a%b);
}
long long rho(long long N)
{
    // f(x) = x*x  + c (mod N)
    long long d = 1;
    long long x = rand() % (N-1) + 1 ;
    long long c = rand() % (N-1) + 1 ;
    long long y = x ;
    if(N%2==0)
        return 2;
    //initially d = 1
    //while d==1 ::::coprime random number
    //1 and N are trivial divisors of N
    while(d==1) 
    {
        //searching for divisors 
        // x = f(x)
        // y = f(f(y))
        x = (mulmod(x,x,N) +c%N )%N;
        y = (mulmod(y,y,N) +c%N )%N;
        y = (mulmod(y,y,N) +c%N )%N;
        d = gcd(abs(x-y),N);
    }
    return d;
}
long long pollard_rho(long long n)
{
    if(n%2==0)return 2;   
    long long x = (rand()%(n-2)) + 2 ;
    long long a = (rand()%(n-2)) + 2;
    long long y = x;
    long long g = 1;
    long long lx = g;
    int cnt = 0;
    while(g==1)
    {
       x = mulmod(x,x,n);
       x+=(a%n);
       y = mulmod(y,y,n);
       y+=(a%n);
       y = mulmod(y,y,n);
       y+=(a%n);
       x = x%n;
       y = y%n;
       g = gcd(absl(x-y),n);
       if(lx==g)
       {
        cnt++;         
       }
       if(cnt>10000)
       {
         x = (rand()%(n-2)) + 2;
         y = x;
         a = (rand()%(n-2)) + 2;         
         cnt = 0;
         g = 1;
         lx = 1;
       }
    }
    return g;
}
vector<long> v;
void factor(long long N)
{
    if(N==1)
        return ;
    if(miller_rabin(N,20)) // if prime factor is coming from recursion 
    {
        v.push_back(N);
        return ;
    }
    long long d = pollard_rho(N);
    /****recursion*****/
    factor(d);//since rho give all divisors (not only prime divisors)
    factor(N/d);// d and N/d are both divisors of N
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
        v.clear();
        factor(n);
        sort(v.begin(),v.end());
        
        long long count = 1;
        long long pro = 1;
        for(int i=0;i<v.size();i++)
        {
            count = 1;
            if((i+1)<v.size() && v[i]==v[i+1])
            {
                while((i+1)<v.size() && v[i]==v[i+1])
                {
                    count++;
                    i++;
                }
                pro *= (expo(v[i-1],count+1)-1)/(v[i-1]-1) ;
		
			
            }
            else
            {
                pro *= (expo(v[i],1+1)-1)/(v[i]-1) ;
		
            }

        }
        
        printf("%lld\n",pro-n);
    }
    
    return 0;
}




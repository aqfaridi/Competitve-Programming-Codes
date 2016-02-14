#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
typedef unsigned long long int  ll ;
using namespace std;
ll mulmod(ll a,ll b,ll m)
{
    ll result = 0 ;
    while(b>0)
    {
        if((b&1))
            result = (result + a)%m;
        
        a = (2*a)%m;
        b >>= 1; 
    }
    return result%m;
}

ll expo(ll a,ll n)
{
    ll result = 1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
ll modulo(ll a,ll n,ll m)
{
    ll result = 1;
    while(n>0)
    {
        if((n&1))
            result = mulmod(result,a,m);
        
        a = mulmod(a,a,m);
        n>>=1;
    }
    return result%m;
}
bool miller_rabin(ll n,int iteration)
{
    if(n<2)
        return false;
    if(n!=2 && n%2==0)
        return false;
    ll d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<iteration;i++)
    {
        ll a = (rand() % (n-1) + 1); //a: 1 to n-1 
        ll temp = d;   // for while stopping condition
        ll mod = modulo(a,d,n);
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

long long pollard_rho(long long n)
{

    long long x=rand()%(n-1)+1;
    long long y=x;
    long long c=rand()%(n-1)+1;
    long long g=1;
    if(n%2==0)
        return 2;
    while(g==1)
    {

        x=((x*x)%n+c)%n;
        y=((y*y)%n+c)%n;
        y=((y*y)%n+c)%n;
        g=gcd(abs(x-y),n);
    }
    return g;
}

ll rho(ll N)
{
    // f(x) = x*x  + c (mod N)
    //ll loop = 0;
    ll x = rand()%(N-1)+1 ;
    ll c = rand()%(N-1)+1  ;
    ll y = x ;
    ll d = 1 ;
    if(N%2==0)
        return 2;
    //initially d = 1
    //while d==1 ::::coprime random number
    //1 and N are trivial divisors of N
    //int thisis=0;
    while(d==1)// && loop<10000) 
    {
        //thisis++;
        //searching for divisors 
        // x = f(x)
        // y = f(f(y))
        //cout<<"infite loop";
        //loop++;
        //cout<<loop<<" ";
        //cout<<thisis<<" ";
        x = (mulmod(x,x,N) +c )%N;
        y = (mulmod(y,y,N) +c )%N;
        y = (mulmod(y,y,N) +c )%N;
        d = gcd(abs(x-y),N);
    }
    return d;
}
vector<ll> v;
void factor(ll N)
{
    /**
    inf++;
    if(inf>100000)
    {
        v.push_back(N);
        return;
    }
    **/
    if(N==1)
        return ;
    if(miller_rabin(N,10)) // if prime factor is coming from recursion 
    {
        cout<<N<<" "; 
        v.push_back(N);
        return ;
    }
    ll d = rho(N);
    cout<<d<<" ";
    /****recursion*****/
    factor(d);//since rho give all divisors (not only prime divisors)
    factor(N/d);// d and N/d are both divisors of N
}
int main()
{
    //checking whether n is prime or not
    int t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        v.clear();
        //factor(n);
        cout<<pollard_rho(25)<<endl;
        sort(v.begin(),v.end());
        /**
        ll count = 1;
        ll pro = 1;
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
        **/
        //printf("%llu\n",pro-n);
    }
    
    return 0;
}


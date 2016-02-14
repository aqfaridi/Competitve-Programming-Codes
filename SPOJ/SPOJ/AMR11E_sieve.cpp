/*******************************
// Name : Abdul Qadir Faridi
// IPG-3rd yr
// Institute : ABV-IIITM,Gwalior
*********************************/

//header files

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>

//Preprocessor directives

#define MAX 100010
#define sqrLim 317
#define MOD 1000000007
#define gc getchar_unlocked

//macros input-output

#define si(n)                       scanf("%d",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(str)                     scanf("%s",str)
#define sd(n)                       scanf("%lf",&n)
#define INF                         INT_MAX
#define LINF                        (LL)1e18
#define maX(a,b)                    ((a)>(b)?(a):(b))
#define miN(a,b)                    ((a)<(b)?(a):(b))
#define abS(x)                      ((x)<0?-(x):(x))
#define    forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    for(i,0,n) 
#define pn()                        printf("\n")
#define pi(n)                       printf("%d",n)
#define pll(n)                      printf("%lld",n)
#define pd(n)                       printf("%lf",n)
#define ps(str)                     printf("%s",str)

//macros stl

#define mp                          make_pair
#define tri(a,b,c)                  mp(a,mp(b,c))
#define pb                          push_back
#define fill(a,v)                   memset(a,v,sizeof a)
#define all(x)                      x.begin(),x.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
#define clear(a)                    memset(a,0,sizeof a)

//debug

#define debug                       if(1)
#define debugoff                    if(0)    

//constants

#define PI                          M_PI
#define E                           M_E
using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

//FAST io

#define input(n) read(&n)
/**
void read(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
**/
#define ifc(n) (flag[n>>6] & (1 << ((n>>1)&31)) )
#define isc(n) (flag[n>>6] |= (1 << ((n>>1)&31)) )
unsigned flag[MAX>>6];
int primes[MAX];
void sieve()
{
    int i,j,k;
    for(i=3;i<=sqrLim;i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i,k=i<<1;j<=MAX;j+=k)
            {
                isc(j);
            }
        }
    }
    k = 0;
    primes[k++] = 2;
    for(i=3;i<=MAX;i+=2)
        if(!ifc(i))
            primes[k++] = i;

}
int kprimes[MAX];
int lucky[MAX];
void prime_factorize()
{
    int n,x=1;
    for(int nn=0;nn<=MAX;nn++)
    {
        
        n = nn;
        for(int i=0;primes[i]*primes[i] < n;i++)
        {
            if(n%primes[i] == 0)
            {
                kprimes[nn]++;
                while(n%primes[i] == 0)
                    n /= primes[i];
            }
        }    
        if(n>1)
            kprimes[nn]++;
        if(kprimes[nn] >=3)
            lucky[x++] = nn;
    }
}
int main()
{
    int t;
    sieve();
    /**********
    for(int i=0;i<100;i++)
        cout<<primes[i]<<" ";
    cout<<endl;
    *******/
    prime_factorize();
    /**********
    for(int i=0;i<100;i++)
        cout<<kprimes[i]<<" ";
    cout<<endl;
    **********/
    int n;
    si(t);
    while(t--)
    {
        si(n);
        printf("%d\n",lucky[n]);    
    }
    return  0;
}


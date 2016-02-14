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

#define MAX 1000010
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

#define ifc(n) (flag[n>>6] & (1 << ((n>>1)&31)) )
#define isc(n) (flag[n>>6] |= (1 << ((n>>1)&31)) )
unsigned flag[MAX>>6];
int primes[1010],nopr;
void sieve()
{
    int i,j,k;
    for(i=3;i<=32;i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i,k=i<<1;j<=1010;j+=k)
            {
                isc(j);
            }
        }
    }
    k = 0;
    primes[k++] = 2;
    for(i=3;i<=1010;i+=2)
        if(!ifc(i))
            primes[k++] = i;
    nopr = k;
}
int kprimes[MAX];

void prime_factorize()
{
    int n;
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
    }
}
**/
int kprimes[MAX];
int pref[11][MAX];
void sieve()
{
    for(int i=2;i<MAX;i+=2)
        kprimes[i] = 1;
    for(int i=3;i < MAX;i+=2)
    {
        if(!kprimes[i])
        {
            kprimes[i] = 1;
            for(int j=(i<<1) ;j<MAX;j+=i)
            {   
                //all multiples of i
                kprimes[j]++;//distinct prime factor is i
            }
        }
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
    //prime_factorize();
   /** 
    for(int i=0;i<100000;i++)
        cout<<kprimes[i]<<" ";
    cout<<endl;
    cout<<kprimes[100000]<<endl;
    **********/
    for(int j=0;j<11;j++)
        for(int i=1;i<MAX;i++)
            if(kprimes[i] == j)
                pref[j][i] = pref[j][i-1] + 1;
            else
                pref[j][i] = pref[j][i-1];
   
    int n,a,b,k,cnt;
    si(t);
    while(t--)
    {
        cnt = 0;
        scanf("%d %d %d",&a,&b,&k);
        printf("%d\n",pref[k][b] - pref[k][a-1]);    
    }
    return  0;
}


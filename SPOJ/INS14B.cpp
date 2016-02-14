#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MOD 1000000007
namespace sieve
{
    #define MAX 1010
    #define LIM 32
    #define PRM 500
    unsigned flag[MAX >> 6];
    unsigned segment[MAX >> 6];
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
    }
}
using namespace sieve;
#define gc getchar_unlocked
inline void readNat(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimisation
         for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

int main()
{
    make_sieve();
    int t,n,cnt;
    LL pro;
    readNat(&t);
    while(t--)
    {
        readNat(&n);
        if((n&1))
        {
            printf("0\n");
            continue;
        }
        n = n*n/2;
        pro = 1;
        for(int i=0;primes[i]*primes[i] <= n;i++)
        {
           if(n%primes[i] == 0)
           {
                cnt = 0;
                while(n%primes[i] == 0)
                {
                    cnt++;
                    n/=primes[i];
                }           
                pro *= (cnt+1);
           }
        }
        if(n>1)
            pro *= 2;
        printf("%lld\n",pro);
    }
    return 0; 
}

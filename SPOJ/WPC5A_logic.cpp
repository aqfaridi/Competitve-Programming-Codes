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
    #define MAX 1000010
    #define LIM 1000
    #define PRM 78500
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
        /*
        for(int i=0;i<100;i++)
            cout<<primes[i]<<" ";
        cout<<k<<endl;
        */
    }
}
using namespace sieve;

LL prime_factorize(LL a)
{
    LL pro=1,cnt;
    for(int i=0;primes[i]*primes[i] <= a;i++)
    {
        if(a%primes[i] == 0)
        {
            cnt = 0;
            while(a%primes[i] == 0)
            {
                cnt++;
                a/=primes[i];
            }
            pro *= (2*cnt+1);
        }
    }
    if(a > 1)
        pro *= 3;
    
    return pro;
}

int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int t;
    LL a,ans;
    cin>>t;
    while(t--)
    {
        cin>>a;
        ans = prime_factorize(a);
        cout<<ans/2<<endl;
    }
    return 0; 
}

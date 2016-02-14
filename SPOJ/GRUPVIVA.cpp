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

#define MAX 32010
#define MOD 1000000007
namespace sieve
{
    #define LIM 179
    #define PRM 3434
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
    }
}
using namespace sieve;
LL prime_factorize(LL R)
{   
    LL pro = 1;
    int cnt;
    for(int i=0;primes[i]*primes[i] <= R;i++)
    {
        if(R % primes[i] == 0)
        {
            cnt = 0;
            while(R % primes[i] == 0)
            {
                cnt++;
                R /= primes[i];
            }
            pro *= (cnt+1);
        }
    }
    if(R > 1)
        pro *= (2);

    return (pro);
}

int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    LL t,N,R;
    LL cuts,cnt,g;
    cin>>t;
    while(t--)
    {
        cin>>N>>R;
        R -= 1;
        cuts = prime_factorize(R);      
        cnt = N - cuts;
        g = __gcd(cnt,N);
        cout<<cnt/g<<"/"<<N/g<<endl;
    }
    return 0; 
}

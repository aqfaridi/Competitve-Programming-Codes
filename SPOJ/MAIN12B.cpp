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

#define MOD 1000000007
LL arr[110];
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
set<LL> s;
set<LL>::iterator it;
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int t,n,cases=0;
    LL num;
    cin>>t;
    while(t--)
    {
        cases++;
        s.clear();
        cin>>n;
        rep(i,n)
            cin>>arr[i];
        rep(i,n)
        {
            num = arr[i];    
            for(int i=0;primes[i]*primes[i]<=num;i++)
            {
                if(num%primes[i] == 0)
                {
                    while(num%primes[i] == 0)
                        num /= primes[i];
                    s.insert(primes[i]);
                }
            }
            if(num > 1)
                s.insert(num);
        }
        it = s.begin();
        cout<<"Case #"<<cases<<": "<<s.size()<<endl;
        for(;it!=s.end();it++)
            cout<<(*it)<<endl;
    }
    return 0; 
}

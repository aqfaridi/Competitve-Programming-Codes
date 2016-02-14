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

#define MAX 1000010
#define LIM 1000
#define PRM 78500
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
map<int,int> m1,m2;
void prime_factorize1(LL n)
{
    int cnt;
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i] == 0)
        {
            cnt = 0 ;
            while(n%primes[i] == 0)
            {
                cnt++;
                n/=primes[i];
            }
            m1[primes[i]] = cnt;
        }
    }
    if(n>1)
        m1[n] = 1;
}

void prime_factorize2(LL n)
{
    int cnt;
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i] == 0)
        {
            cnt = 0 ;
            while(n%primes[i] == 0)
            {
                cnt++;
                n/=primes[i];
            }
            m2[primes[i]] = cnt;
        }
    }
    if(n>1)
        m2[n] = 1;
}
map<int,int>::iterator it;
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int t;
    bool flag;
    LL a,b,c,d,p,pwr;
    cin>>t;
    while(t--)
    {
        m1.clear();
        m2.clear();
        cin>>a>>b>>c>>d;
        //a^b / c^d
        prime_factorize1(a);
        prime_factorize2(c);
        
        it = m2.begin();
        flag = true;
        for(;it != m2.end();it++)
        {
            p = it->first;
            pwr = it->second;
            //trace2(p,pwr);
            
            if(m1[p]*b < pwr*d)
            {
                //cout<<p<<endl;
                //trace2(m1[p],pwr);
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;
    }
    return 0; 
}

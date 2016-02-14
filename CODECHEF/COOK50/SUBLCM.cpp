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
#include <climits>
#include <cassert>

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
    int primes[PRM];
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
int mark[MAX],a[MAX];
int start,maxx;

void factorsieve()
{
        for(int i=1;i<MAX;i++)
                    a[i]=i;
 
        for(int i=2;i*i<=MAX;i++)
        {
           if(a[i] == i)
           {
                for(int j=i*i;j<MAX;j+=i)
                {
                      if(a[j] == j)
                      {
                             a[j]=i;
                      }
                 }
           }
 
        }
}

void prime_factorize(int n,int idx)
{
    for(int i=0;1LL*primes[i]*primes[i] <= n;i++){
        if(n%primes[i] == 0){
            while(n%primes[i] == 0){
                n/=primes[i];
            }
            if(!mark[primes[i]] || mark[primes[i]] < start)
                mark[primes[i]] = idx;
            else{
                mark[primes[i]] = idx;
                maxx = max(maxx,idx-start);
                start = idx;
            }
        }
    }
    if(n>1){
        if(!mark[n] || mark[n] < start)
            mark[n] = idx;
        else{
            mark[n] = idx;
            maxx = max(maxx,idx-start);
            start = idx;
        }
    }
}
void factr(int n,int idx){
        int temp=a[n];
        n /= a[n];
        int count=1;
        while(a[n]!=1)
        {
            //cout<<"temp="<<temp<<" a[n]="<<a[n]<<endl;
            if(temp == a[n])
                count++;
            else
            {
                //nod*=(count+1);

                if(!mark[temp] || mark[temp] < start)
                    mark[temp] = idx;
                else{
                    mark[temp] = idx;
                    maxx = max(maxx,idx-start);
                    start = idx;
                }
                temp = a[n];                
                count=1;
            }
            n/=a[n];
        }

            if(!mark[temp] || mark[temp] < start)
                mark[temp] = idx;
            else{
                mark[temp] = idx;
                maxx = max(maxx,idx-start);
                start = idx;
            }
}
int main()
{
    factorsieve();
    ios::sync_with_stdio(false);
    int t,n,var;
    cin>>t;
    while(t--)
    {
        cin>>n;
       
        memset(mark,0,sizeof(mark));
        start = 1;
        maxx = 0;
        for(int i=1;i<=n;i++){
            cin>>var;
            factr(var,i);
        }
        factr(var,n+1);

        if(maxx == 1)
            cout<<-1<<endl;
        else
            cout<<maxx<<endl;
    }
    return 0; 
}


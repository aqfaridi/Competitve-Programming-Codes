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
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 100010
#define MOD 1000000007
namespace sieve
{
    #define MaX 100010
    #define LIM 320
    #define PRM 78500
    typedef long long LL;
    unsigned flag[MaX >> 6];
    unsigned segment[MaX >> 6];
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
                for(j=i*i,k=(i<<1);j<MaX;j+=k)
                    isc(j);
        }
        primes[0] = 2;
        for(i=3,k=1;i<MaX;i+=2)
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
int arr[MAX];
vector<int> ans[MAX];
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int t,n,m,G,x,y,maxx,num,mm,ct,size,cnt,l,r,idx,idx2,idx1;
    t = 1;
    while(t--)
    {
        cin>>n>>m;

        for(int i=1; i<=n; i++) 
        {
            int a;
            cin>>arr[i];
            num = arr[i];
            int j;
            for(j=0;primes[j]*primes[j] <= num; j++) 
            {
                if(num % primes[j] == 0) 
                    ans[primes[j]].push_back(i);
                while(num % primes[j] == 0)
                    num /= primes[j];
            }
            if(num > 1)
                ans[num].push_back(i);
        }
        int j;
        rep(k,m)
        {
            cin>>G>>l>>r;
            if(G == 1)
            {
                cout<<-1<<" "<<-1<<endl;
                continue;
            }
            maxx = -1;cnt = 0;
            for(j=0;primes[j]*primes[j]<=G; j++) 
            {               
                if(G%primes[j] == 0) 
                {
                    mm = -1;
                    idx2 = upper_bound(ans[primes[j]].begin(),ans[primes[j]].end(),r) - ans[primes[j]].begin();
                    idx1 = upper_bound(ans[primes[j]].begin(),ans[primes[j]].end(),l) - ans[primes[j]].begin();
                    
                    if(idx1 >=1 && ans[primes[j]][idx1-1] == l)
                        idx1 -= 1;
                    for(int idx = idx1;idx<idx2;idx++)
                    {
                        if(arr[ans[primes[j]][idx]] > mm)
                        {
                            mm = arr[ans[primes[j]][idx]];
                            ct = 0;
                        }
                        if(arr[ans[primes[j]][idx]] == mm) ct++;                        
                    }    
                    if((mm > maxx) || (mm==maxx && ct > cnt))
                    {
                        maxx = mm;
                        cnt = ct;
                    }
                    while(G%primes[j] == 0)
                            G/=primes[j];
                
                }
            }    
            if(G > 1) 
            {
                mm = -1;
                idx2 = upper_bound(ans[G].begin(),ans[G].end(),r) - ans[G].begin();
                idx1 = upper_bound(ans[G].begin(),ans[G].end(),l) - ans[G].begin();
                
                    if(idx1 >=1 && ans[G][idx1-1] == l)
                        idx1 -= 1;
                for(int idx = idx1;idx<idx2;idx++)
                {
                    if(arr[ans[G][idx]] > mm)
                    {
                        mm = arr[ans[G][idx]];
                        ct = 0;
                    }
                    if(arr[ans[G][idx]] == mm) ct++;
                }

                if((mm > maxx) || (mm==maxx && ct > cnt))
                {
                    maxx = mm;
                    cnt = ct;
                }
            }
            if(maxx != -1)
                cout<<maxx<<" "<<cnt<<endl;
            else
                cout<<-1<<" "<<-1<<endl;
        }
    }
    return 0; 
}

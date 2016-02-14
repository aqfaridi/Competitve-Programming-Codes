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

#define MAX 100010
#define MOD 1000000007
int parent[MAX],mark[MAX];
map<int,int> m;
void prime_factorize(int n)
{
    int cnt = 0;
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            m[i] = max(m[i],cnt);
        }
    if(n > 1)
        m[n] = max(m[n],1);
}
LL expo(int a,int n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result = (result * a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return result % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,ptr;
    LL cnt,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>parent[i];
        m.clear();
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=n;i++)
        {
            if(!mark[i])
            {
                ptr = parent[i];cnt = 0;
                do{
                    cnt++; mark[ptr] = 1;
                    ptr = parent[ptr];
                }while(ptr != parent[i]);

                prime_factorize(cnt);
            }
        }
        
        map<int,int>::iterator it=m.begin();     
        ans = 1;
        for(;it != m.end();it++)
            ans = (ans%MOD * expo(it->first , it->second))%MOD;
        cout<<ans<<endl;
    }
    return 0; 
}

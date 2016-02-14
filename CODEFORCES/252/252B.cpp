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

#define MAX 100010
#define MOD 1000000007
#include <climits>
vector< pii > v;
int main()
{
    ios::sync_with_stdio(false);
    int nt,nf,a,b,tod,temp,minn=INT_MAX,maxx = INT_MIN;
    cin>>nt>>nf;
    for(int i=0;i<nt;i++)
    {
        cin>>a>>b;
        v.pb(mp(a,b));
        minn = min(minn,a);
        maxx = max(maxx,a);
    }
    sort(v.begin(),v.end());
    int k=minn,ans = 0;

    
    tod = nf;
    for(int i=0;i<nt;i++)
        if(v[i].first == k)
        {
            temp = min(v[i].second,tod);
            v[i].second -= temp;
            tod -= temp; 
            ans += temp;
        }
   //trace2(k,ans);
    
    while(k<=maxx)
    {
        tod = nf;
        for(int i=0;i<nt;i++)
            if(v[i].first == k || (v[i].first == k+1))
            {
                temp = min(v[i].second,tod);
                v[i].second -= temp;
                tod -= temp; 
                ans += temp;
            }
        k++;
    }

    cout<<ans<<endl;
    return 0; 
}

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

#define MAX 110
#define MOD 1000000007
vector<pii> v;
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,vr,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        v.pb(mp(arr[i],i));
    }
    
        int ans = 1;
        for(int i=0;i<v.size();)
        {
            if(v.size() == 1) {ans = v[0].second; break; }
            v[i].first -= m;
            if(v[i].first > 0)
                v.pb(mp(v[i].first,v[i].second));
            v.erase(v.begin());
        }
      
        cout<<ans<<endl;
        
        return 0; 
}

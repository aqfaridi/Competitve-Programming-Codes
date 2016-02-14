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
vector< pair<LL,LL> > v,q;
int main()
{
    ios::sync_with_stdio(false);
    LL n,s,e,xi,pi,l,r;
    cin>>n>>s>>e;
    rep(i,n){
        cin>>xi>>pi;
        v.pb(mp(xi-pi,xi+pi));
    }
    sort(all(v));
    //rep(i,n)
      //  trace2(v[i].first,v[i].second);

    int size = v.size();
    l = v[0].first;
    r = v[0].second;
    for(int i=1;i<size;i++){
        if(v[i].first <= r)
            r = max(r,v[i].second);
        else{
            q.pb(mp(l,r));
            l = v[i].first;
            r = v[i].second;
        }
    }
    
    q.pb(mp(l,r));

    size = q.size();
    l = r = s;
    LL ans = 0;
    for(int i=0;i<size;i++)
    {
        if(q[i].first > e)
            break;

        if(q[i].first >= s){
            //trace2(q[i].first,q[i].second);
             if(r >= s && q[i].first <= e) 
                ans += max(min(e,q[i].first) - r,0LL);
            //cout<<r<<" "<<q[i].first<<endl;
            r = q[i].second;
        }
    }

    ans += max(e - r,0LL);
    cout<<ans<<endl;
    return 0; 
}


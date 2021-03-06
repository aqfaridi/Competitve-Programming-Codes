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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
vector< pii > s;
queue<int> q;
int d[MAX],xs[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i]>>xs[i];
        if(d[i] == 1)   q.push(i);
    }

    while(!q.empty()){
        u = q.front(); q.pop();
        if(d[u] == 0)   continue;
        
        v = xs[u];
        xs[v] ^= u;        
        d[v] -=1; d[u] = 0;

        if(d[v] == 1) q.push(v);
        s.pb(mp(u,v));
    }

    int ans = s.size();
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
        cout<<s[i].first<<" "<<s[i].second<<endl;
    
    return 0; 
}


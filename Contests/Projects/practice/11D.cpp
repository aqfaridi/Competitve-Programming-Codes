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
LL n,mem[(1<<19)][20];//number of cycles which starts at i & having nodes from mask
LL g[20];
LL solve(int mask,int s,int t,int parent = -1){//s = source & t = target
    
    if(s == t && parent != -1)  return 1;
    
    LL& res = mem[mask][s];
    if(res != -1)   return res;

    res = 0;
    for(int i=0;i<=t;i++){        
        if((i != parent) && !(mask & (1<<i)) && (g[s] & (1<<i)) ) { //no back path & valid edge too
            res += solve(mask | (1<<i) ,i,t,s);
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a -= 1; b -= 1;
        g[a] |= (1<<b);
        g[b] |= (1<<a); //undirected graph
    }
    
    LL ans = 0;
    for(int i=0;i<n;i++){
        memset(mem,-1,sizeof mem);
        ans += solve(0,i,i);
    }

    cout<<ans/2<<endl;//cycles are counted twice forward & backward
    return 0; 
}


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

int main()
{
    ios::sync_with_stdio(false);
    int q,i,len;
    string s;
    string ans = "";
    char ch;
    cin>>q;
    while(q--)
    {
        cin>>ch;
        if(ch == '+')
        {
            cin>>i>>s;
            ans = ans.substr(0,i) + s + ans.substr(i); 
        }
        else
        {
            cin>>i>>len;
            i -= 1;
            cout<<ans.substr(i,len)<<endl;
        }
    }

    return 0; 
}
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

#define MAX 10010
#define MOD 1000000007
vector<int> adjList[MAX];
bool visited[MAX];
int depth[MAX],parent[MAX];
void DFS(int node,int d)
{
    depth[node] = d;
    visited[node] = true;
    int size = adjList[node].size();
    for(int i=0;i<size;i++)
    {
        int child = adjList[node][i];
        if(!visited[child])
        {
            parent[child] = node;
            DFS(child,d+1);
        }
    }
}

int P[MAX][14],n;
void preProcess()
{
    for(int i=0;i<=n;i++)
        for(int j=0;1<<j <= n;j++)
            P[i][j] = -1;
    for(int i=0;i<=n;i++)
        P[i][0] = parent[i];
    for(int j=1;1<<j < n;j++)
        for(int i=0;i<=n;i++)
            if(P[i][j-1] != -1)
                P[i][j] =  P[P[i][j-1]][j-1];
}
int query_lca(int p,int q)
{
    int lg;
    if(depth[p] < depth[q])
        swap(p,q);
    lg = log2(depth[p]);
    for(int i=lg;i>=0;i--)
        if(depth[p] - (1<<i) >= depth[q])
            p = P[p][i];

    if(p == q)
        return p;

    for(int i=lg;i>=0;i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i],q = P[q][i];
    return parent[p];
}

void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        adjList[i].clear();
        depth[i] = 0;
        parent[i] = -1;
        visited[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,m,q,var,a,b,cases=0;
    cin>>t;
    while(t--)
    {
        cases++;
        cout<<"Case "<<cases<<":"<<endl;
        cin>>n;
        reset(n);
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>var;
                adjList[i].pb(var);
                adjList[var].pb(i);
            }
        }
        DFS(1,0);
        preProcess();
        cin>>q;
        rep(i,q)
        {
            cin>>a>>b;
            cout<<query_lca(a,b)<<endl;
        }
        
    }
    return 0; 
}


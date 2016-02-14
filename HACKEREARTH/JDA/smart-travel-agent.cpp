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
vector< pii > adjList[MAX];
int visited[MAX],parent[MAX],d,men,maxx;
int route[MAX],n;
void DFS(int node,int cost)
{
    if(node == d)
        if(maxx < cost)
        {
            maxx = cost;
            for(int i=0;i<=n;i++)
                route[i] = parent[i];
        }
    
    visited[node] = 1;
    int child,c,size = adjList[node].size();
    for(int i=0;i<size;i++)
    {
        child = adjList[node][i].first;
        c = adjList[node][i].second;
        //trace2(child,c);
        if(!visited[child])
        {
            parent[child] = node;
            DFS(child,min(cost,c));
        }
    }
    visited[node] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int m,u,v,c,s;
    maxx = -1;
    memset(visited,0,sizeof(visited));

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        adjList[u].pb(mp(v,c));
        adjList[v].pb(mp(u,c));
    }
    cin>>s>>d>>men;
    DFS(s,(1<<20));
    maxx -= 1;
    
    int notrips = (men + (maxx-1))/maxx;
    
    int i = d;
    vector<int> path;
    path.pb(d);
    while(i != s)
    {
        path.pb(route[i]);
        i = route[i];
    }
        
    for(int i=path.size()-1;i>=0;i--)
        cout<<path[i]<<" ";
    cout<<endl;
    cout<<notrips<<endl;


    return 0; 
}

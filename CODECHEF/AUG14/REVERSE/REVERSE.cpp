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
vector< pii > adjList[MAX];
int dist[MAX];
bool visited[MAX];
void dijkstra(int s,int d)
{
    priority_queue< pii , vector< pii > , greater< pii > > q; //min heap
    q.push(mp(0,s));
    int u,v,w,size;
    dist[s] = 0;
    while(!q.empty())
    {
        u = q.top().second;
        q.pop();
        
        if(visited[u])  continue;
        if(u == d)  break;

        size = adjList[u].size();
        rep(i,size){
            v = adjList[u][i].first;
            w = adjList[u][i].second;
            if(!visited[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.push(mp(dist[v],v));
            }
        }
        visited[u] = true;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,u,v;
    memset(dist,31,sizeof(dist));
    cin>>n>>m;
    rep(i,m){
        cin>>u>>v;
        adjList[u].pb(mp(v,0));
        adjList[v].pb(mp(u,1));
    }
    dijkstra(1,n);
    if(dist[n] > m)
        cout<<-1<<endl;
    else
        cout<<dist[n]<<endl;

    return 0; 
}

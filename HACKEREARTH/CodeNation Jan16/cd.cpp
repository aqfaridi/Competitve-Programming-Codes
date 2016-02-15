#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007

int n,m;
vector< pii > adjList[3010];
vector< pii > adj[3010];
vector<bool> status(3010);
LL dist[3010][3010];
void dijkstra(int s,int d)
{
    if(dist[s][d] != 0) return;

    for(int i=0;i<=n;i++)
    {
        status[i] = false;
        dist[s][i] = INT_MAX;
    }

    priority_queue< pii , vector< pii > , greater< pii > > q;
    q.push(mp(0,s));
    dist[s][s] = 0;
    int u,v,w,wT,size;
    while(!q.empty())
    {
        u = q.top().second;
        q.pop();

        if(status[u])
            continue;

        if(u == d)
            break;

        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            v = adjList[u][i].second;
            w = adjList[u][i].first;
            if(!status[v] && dist[s][u] + w < dist[s][v])
            {
                dist[s][v] = dist[s][u] + w;
                q.push(mp(dist[s][v],v));//min heap acc to dist[v]
            }
        }
        status[u] = true;
    }
}

int main()
{
    int t,u,v,r,T,s,d;
    scanf("%d",&t);
    while(t--)
    {

        memset(dist,0,sizeof dist);
        scanf("%d %d",&n,&m);
        
        for(int i=1;i<=n;i++){
           adjList[i].clear();
           adj[i].clear();
       }
       for(int i=1;i<=m;i++){
            scanf("%d %d %d %d",&u,&v,&r,&T);
            adj[u].pb(mp(T,v));
            adj[v].pb(mp(T,u));
            adjList[u].pb(mp(r,v));
            adjList[v].pb(mp(r,u));
        }

        scanf("%d %d",&s,&d);
        dijkstra(s,d);

        LL ans = dist[s][d];
        if(ans == INT_MAX)
            printf("-1\n");
        else{
            dijkstra(d,s);
            for(int i=1;i<=n;i++)
                for(int j=0;j<adj[i].size();j++)
                     ans = min(ans,dist[s][i] + adj[i][j].first + dist[d][adj[i][j].second]);             
            printf("%lld\n",ans);
        }
    }
    return  0;
}


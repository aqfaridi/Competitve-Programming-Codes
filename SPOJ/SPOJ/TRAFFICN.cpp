#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 10010
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
const int INF = 0x3f3f3f;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
vector< pii > adjList[MAX];
vector< pii > rev_adjList[MAX];
bool status[MAX],rev_status[MAX];
int dist[MAX],rev_dist[MAX];

void dijkstra(int s,int d,int *dist,bool *status,vector< pii > *adjList)
{
    priority_queue< pii , vector< pii > , greater< pii > > q;//type of element , container , comparator
    int u,v,w,size;
    q.push(pii(0,s));
    dist[s] = 0;
    while(!q.empty())
    {
        u = q.top().second; // vertex;
        q.pop();
        if(status[u])   continue;//already visited
        if(s == d)  break;
        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            v = adjList[u][i].second;
            w = adjList[u][i].first;
            if(!status[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push(pii(dist[v],v));
            }
        }
        status[u] = true;
    }
}
int main()
{
    int test,n,m,k,s,t,cost,u,v,w;
    scanf("%d",&test);
    while(test--)
    {


        scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
        
        for(int i=1;i<=n;i++)
        {
            rev_adjList[i].clear();
            adjList[i].clear(); 
            status[i] = false;
            dist[i] = INF;
            rev_dist[i] = INF;
            rev_status[i] = false;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            // undirected roads
            adjList[u].pb(mp(cost,v));
            rev_adjList[v].pb(mp(cost,u));
        }
            
        dijkstra(s,t,dist,status,adjList);        
        dijkstra(t,s,rev_dist,rev_status,rev_adjList);
        int minn = INF;
        /*
        for(int i=0;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
        for(int i=0;i<=n;i++)
            cout<<rev_dist[i]<<" ";
        cout<<endl;
        */
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            //cout<<dist[u]<<endl;
            //cout<<rev_dist[v]<<endl;
            //cout<<w<<endl;
            //cout<<dist[u]+w+rev_dist[v]<<endl;
            //cout<<dist[v]+w+rev_dist[u]<<endl;
            minn = min(minn,min(dist[t],min(dist[u]+w+rev_dist[v],dist[v]+w+rev_dist[u])));
        }
        if(minn < INF )
            printf("%d\n",minn);
        else
            printf("-1\n");

    }
    return 0;
}


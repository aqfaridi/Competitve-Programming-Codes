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
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
vector< pii > adjList[MAX];
vector<int> dist(MAX);
vector<bool> status(MAX);
int N;

void dijkstra(int s,int d)
{
    dist.assign(N+1,INT_MAX);
    status.assign(N+1,false);
    priority_queue< pii , vector< pii > , greater< pii > > q;
    q.push(pii(0,s));
    dist[s] = 0;
    int u,v,w,size;
    while(!q.empty())
    {
        u = q.top().second; // vertex
        q.pop();
        if(status[u]) continue; //already visited
        if(u == d) break;
        size = adjList[u].size();
        for(int i=0 ; i<size ; i++)
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
    int E,T,M,u,v,cost;
    scanf("%d %d %d %d",&N,&E,&T,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d",&u,&v,&cost);
        //directed
        adjList[u].pb(mp(cost,v));
    }
    int count = 0;
    for(int i=1;i<=N;i++)
    {
        dijkstra(i,E);
        if(dist[E]<=T)
            count++;
    }
    printf("%d\n",count);
    return 0;
}


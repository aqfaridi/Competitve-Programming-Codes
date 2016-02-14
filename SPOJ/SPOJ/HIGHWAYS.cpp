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
vector<int> timee(MAX);
vector<bool> status(MAX);
int n;
void dijkstra(int s,int d)
{
    for(int i=0;i<=n;i++)
    {
        status[i] = false;
        timee[i] = INT_MAX;
    }
    priority_queue< pii , vector< pii > , greater< pii > > q;
    q.push(mp(0,s));
    timee[s] = 0;
    int u,v,w,size;
    while(!q.empty())
    {
        u = q.top().second;//vertex;
        q.pop();
        if(status[u]) continue;//already visited
        if(u == d) break;
        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            v = adjList[u][i].second;
            w = adjList[u][i].first;
            if(!status[v] && timee[v] > timee[u]+w)
            {
                timee[v] = timee[u] + w;
                q.push(mp(timee[v],v));
            }
        }
        status[u] = true;
    }
}
int main()
{
    int test,m,s,t,u,v,cost;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(int i=0;i<=n;i++)
            adjList[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            //bidirectional highways
            adjList[u].pb(mp(cost,v));
            adjList[v].pb(mp(cost,u));
        }
        dijkstra(s,t);   
        if(timee[t] != INT_MAX)
            cout<<timee[t]<<endl;
        else 
            cout<<"NONE"<<endl;
    }
    return 0;
}


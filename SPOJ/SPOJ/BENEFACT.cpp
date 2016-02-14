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
#define MAX 50010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector< pair<int,int> > adjList[MAX];
vector<int> dist(MAX);
vector<bool> visited(MAX);
void reset(int n)
{
    dist.assign(n+1,0);
    visited.assign(n+1,false);
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    int v,size,w;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        visited[u] = true;
        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            //adjacent
            v = adjList[u][i].first;
            w = adjList[u][i].second;
            if(!visited[v])
            {
                dist[v] += (dist[u] + w);
                q.push(v);
            }
        }
    }
}
void DFS(int u)
{
    visited[u] = true;
    int size = adjList[u].size(),v,w; 
    for(int i=0;i<size;i++) //adjacent
    {
        v = adjList[u][i].first;
        w = adjList[u][i].second;
        
        if(!visited[v])
        {
            dist[v] += (dist[u] + w);
            DFS(v);
        }
    }
}
int main()
{
    int t,n,u,v,cost;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        //tree is undirected
        for(int i=0;i<=n;i++)
            adjList[i].clear();
        reset(n);
        for(int i=1;i<=n-1;i++) //since it is a tree (n-1)edges
        {
            scanf("%d %d %d",&u,&v,&cost);
            adjList[u].push_back(make_pair(v,cost));
            adjList[v].push_back(make_pair(u,cost));
        }
        dist.resize(n+1);
        BFS(1);
        int maxx = -1,node;
        for(int i=1;i<=n;i++)
        {
            if(dist[i] > maxx)
            {
                maxx = dist[i];
                node = i;
            }
        }
        /**
        for(int i=0;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<maxx<<" "<<node<<endl;
        **/
        reset(n);
        BFS(node);
        cout<<*max_element(dist.begin(),dist.end())<<endl;
    }
    return 0;
}


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
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
int total;
vector< pair< int , pii > > graph,mst;
vector<int> parent(MAX);
void reset(int n)
{
    graph.clear();
    mst.clear();
    total = 0;
    for(int i=0;i<=n;i++)
        parent[i] = i;    
}
int findset(int x)   //for finding parent
{
    if(parent[x] != x)
        parent[x] = findset(parent[x]);
    return parent[x];
}
void kruskal(int m)
{
    int pu,pv;
    sort(graph.begin(),graph.end()); //increasing weight

    for(int i=0;i<m;i++)
    {
        pu = findset(graph[i].second.first);
        pv = findset(graph[i].second.second);
        if(pu != pv) // not in the same set => does not forming cycle
        {
            mst.push_back(graph[i]);
            total += graph[i].first;
            parent[pu] = parent[pv]; //union
        }

    }
}
int main()
{
    int t,n,m,price,u,v,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&price,&n,&m);
        reset(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&len);            
            //undirected 
            //but only storing all the edges in graph as forest
            graph.push_back(make_pair(len,make_pair(u,v)));
        }
        /**
        for(int i=0;i<m;i++)
        {
            cout<<graph[i].second.first<<" "<<graph[i].second.second<<endl;
        }**/

        kruskal(m);
        printf("%d\n",total*price);
    }
    return 0;
}


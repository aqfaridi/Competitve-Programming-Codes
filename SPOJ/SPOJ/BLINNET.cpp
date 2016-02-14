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
#define DEBUG if(0)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
map<string,int> mymap;
vector< pair< int , pii > > graph,mst;
vector<int> parent(MAX);
int total;
void reset(int n)
{
    mymap.clear();
    graph.clear();
    mst.clear();
    total = 0;
    for(int i=0;i<=n;i++)
        parent[i] = i ;
}
int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);//path compression
    return parent[x];
}
void kruskal(int m)
{
    //mistake: not sorted
    sort(graph.begin(),graph.end());//increasing weight
    int pu,pv;
    for(int i=0;i<m;i++)
    {
        pu = findset(graph[i].second.first);
        pv = findset(graph[i].second.second);
        if(pu != pv) //does not forming cycle
        {
            mst.push_back(graph[i]);
            total += graph[i].first;
            parent[pu] = parent[pv];//union
        }
    }

    /*******print mst ******/
    DEBUG
    for(int i=0;i<mst.size();i++)
    {
        cout<<mst[i].second.first <<" "<<mst[i].second.second<<" "<<mst[i].first<<endl;
    }

}
int main()
{
    int t,n,m,rel,u,v,cost;
    string city;
    scanf("%d",&t);
    while(t--)
    {
        m = 0;
        scanf("%d",&n);
        reset(n);

        for(int i=1;i<=n;i++)
        {
            cin>>city;
            mymap[city] = i;
            scanf("%d",&rel);
            m += rel; 
            u = i;
            for(int j=0;j<rel;j++)
            {
                scanf("%d %d",&v,&cost);
                //roads
                //only edges are required
                graph.push_back(make_pair(cost,make_pair(u,v)));            
            }            
        }
        kruskal(m);
        cout<<total<<endl;
    }
    return 0;
}


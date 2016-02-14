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
int n;
vector<int> adjList[MAX];
vector<bool> visited(MAX);
vector<int> L(MAX);
vector<int> parent(MAX);

void DFS(int node,int level)
{
    visited[node] = true;
 
    int v,size = adjList[node].size(); //adjacent/descendent
    for(int i=0;i<size;i++)
    {
        v = adjList[node][i];
        if(!visited[v])
        {
            DFS(v,level+1);
            parent[v] = node;
            L[v] = level + 1;
        }
    }
}
int main()
{
    int t,q,rel,u,v,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            visited[i] = false;
            adjList[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&rel);
            for(int j=0;j<rel;j++)
            {
                scanf("%d",&v);
                //tree - is always undirected
                adjList[i].push_back(v);
                adjList[v].push_back(i);
            }       
        }
        parent[1] = 0;
        L[1] = 0;
        DFS(1,0);//root and level
        /**
        for(int i=0;i<=idx;i++)
            cout<<E[i]<<" ";
        cout<<endl;
        for(int i=0;i<=idx;i++)
            cout<<L[i]<<" ";
        cout<<endl;
        for(int i=0;i<=n;i++)
            cout<<H[i]<<" ";
        cout<<endl;
        cout<<idx<<endl;        
        **/ 
        
        scanf("%d",&q);
        printf("Case %d:\n",cases); 
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&u,&v);
            while(u != v)
            {
                if(L[v] > L[u])
                    v = parent[v];
                else if(L[u] > L[v])
                    u = parent[u];
                else if(L[u] == L[v])
                {
                    v = parent[v];
                    u = parent[u];
                }
            }
            printf("%d\n",u);
        }
    }
    return 0;
}


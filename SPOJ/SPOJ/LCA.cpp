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
int n,idx=0;
vector<int> adjList[MAX];
vector<bool> visited;
vector<int> L;
vector<int> E;
vector<int> H;
vector<int> tree;
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = b; //storing indexes in seg_tree
        return;
    }
    int mid = (b+e)/2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    if(L[tree[2*node]] <= L[tree[2*node+1]])
        tree[node] = tree[2*node];
    else
        tree[node] = tree[2*node+1];
}

int query(int node,int b,int e,int i,int j)
{
    //i be j
    if(b>=i && e<=j)
        return tree[node];
    //be ij    or  ij be
    if(i>e || j<b)
        return -1;
    int mid = (b+e)/2;

    int p1 = query(2*node,b,mid,i,j);
    int p2 = query(2*node+1,mid+1,e,i,j);

    if(p1 == -1)
        return p2;
    else if(p2 == -1)
        return p1;
    else if(L[p1] <= L[p2])
        return p1;
    else
        return p2;

}

void DFS(int node,int level)
{
    idx++;
    E[idx] = node; //Euler path
    L[idx] = level;
    H[node] = idx; 
    visited[node] = true;
 
    int v,size = adjList[node].size(); //adjacent/descendent
    for(int i=0;i<size;i++)
    {
        v = adjList[node][i];
        if(!visited[v])
        {
            DFS(v,level + 1);
            //on backtracking
            idx++;
            E[idx] = node;
            L[idx] = level;
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
        idx = 0;
        scanf("%d",&n);
        L.resize((n+1)*(n+1));
        H.resize(n+1);
        E.resize((n+1)*(n+1));
        visited.resize(n+1);
        tree.resize((2*n+1)<<2);        
        tree.assign((2*n+1)<<2,0);

        for(int i=0;i<=n;i++)
        {
            adjList[i].resize(n+1);
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
        build(1,1,idx);
        
        scanf("%d",&q);
        printf("Case %d:\n",cases); 
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&u,&v);
            //call query
            //cout<<min(H[u],H[v]) <<" "<<max(H[u],H[v])<<endl;
            int level_index = query(1,1,idx,min(H[u],H[v]),max(H[u],H[v]));
            //cout<<level_index<<endl;    
            printf("%d\n",E[level_index]);
        }
    }
    return 0;
}


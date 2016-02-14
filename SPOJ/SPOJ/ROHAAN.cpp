/*******************************
// Name : Abdul Qadir Faridi
// IPG-3rd yr
// Institute : ABV-IIITM,Gwalior
*********************************/

//header files

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

//Preprocessor directives

#define MAX 1000010
#define MOD 1000000007
#define gc getchar_unlocked

//macros input-output

#define si(n)                       scanf("%d",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(str)                     scanf("%s",str)
#define sd(n)                       scanf("%lf",&n)
#define INF                         INT_MAX
#define LINF                        (LL)1e18
#define maX(a,b)                    ((a)>(b)?(a):(b))
#define miN(a,b)                    ((a)<(b)?(a):(b))
#define abS(x)                      ((x)<0?-(x):(x))
#define    forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    for(i,0,n) 
#define pn()                        printf("\n")
#define pi(n)                       printf("%d",n)
#define pll(n)                      printf("%lld",n)
#define pd(n)                       printf("%lf",n)
#define ps(str)                     printf("%s",str)

//macros stl

#define mp                          make_pair
#define tri(a,b,c)                  mp(a,mp(b,c))
#define pb                          push_back
#define fill(a,v)                   memset(a,v,sizeof a)
#define all(x)                      x.begin(),x.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
#define clr(a)                    memset(a,0,sizeof a)

//debug

#define debug                       if(1)
#define debugoff                    if(0)    

//constants

#define PI                          M_PI
#define E                           M_E
using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

//FAST io

#define input(n) read(&n)
/**
void read(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
**/
int n;
vector< pii > adjList[100];
vector<bool> status(100);
vector<int> dist(100);
void dijkstra(int s,int d)
{
    for(int i=0;i<=n;i++)
    {
        status[i] = false;
        dist[i] = INT_MAX;
    }
    priority_queue< pii , vector< pii > , greater< pii > > q;
    q.push(mp(0,s));
    dist[s] = 0;
    int u,v,w,size;
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
            if(!status[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w ;
                q.push(mp(dist[v],v));//min heap acc to dist[v]
            }
        }
        status[u] = true;
    
    }

}

int main()
{
    int t,cost,u,v;
    int q,cases=0;
    LL sum ;
    si(t);
    while(t--)
    {
        cases++;
        sum = 0;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
           adjList[i].clear();

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&cost);
                //(u -> v) cost if diff from (v -> u)
                adjList[i].pb(mp(cost,j));
            }

        si(q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&u,&v);
            dijkstra(u,v);
            if(dist[v] != INT_MAX)
                sum += dist[v];
        }
        printf("Case #%d: ",cases);
        pll(sum);
        pn();

    }
    return  0;
}


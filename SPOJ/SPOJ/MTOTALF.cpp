/*******************************
// Author : Abdul Qadir Faridi
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
#define rep(i,n)                    forr(i,0,n) 
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
#define clr(a)                      memset(a,0,sizeof a)

//Translator

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

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
int src,snk,nnode,nedge;
int fin[MAX];//stores last index of list of adjacent nodes
int dist[MAX];//for labelling
int cap[MAX];//capacity of edges
int next[MAX];//pointer to next link in list
int to[MAX];//u -> v (storing v)
int q[MAX];
int pro[MAX];
void init(int _src,int _snk,int n)
{
    src = _src;
    snk = _snk;
    nnode = n;
    nedge = 0;
    memset(fin,-1,sizeof(fin));
}
void add(int u,int v,int c)
{
    to[nedge] = v;
    cap[nedge] = c;
    next[nedge] = fin[u];
    fin[u] = nedge++;
    //reverse edges
    to[nedge] = u;
    cap[nedge] = c;
    next[nedge] = fin[v];
    fin[v] = nedge++;
}
bool bfs() //construct Lf from Gf
{
    int e,u,v,enq,deq;
    memset(dist,-1,sizeof(dist));
    dist[src] = deq = enq = 0;
    //naive queue
    q[enq++] = src;
    while(deq < enq)
    {
        u = q[deq++];
      
        for(e = fin[u] ; e>=0 ; e = next[e])
        {
            v = to[e];
            if(cap[e]>0 && dist[v] == -1)//not yet labelled
            {
                dist[v] = dist[u] + 1;
                q[enq++] = v;
            }
        }
    }
    if(dist[snk]==-1)//not possible augmenting path
        return false;
    else
        return true;
}
int dfs(int u,int flow)//find blocking flow(saturated edge) w.r.t Lf
{
    if(u==snk)//base case
        return flow;
    int v,df;
    for(int &e = pro[u];e>=0;e=next[e])
    {
        v = to[e];
        if(cap[e]>0 && dist[v] == dist[u]+1) //condtion for labelled graph
        {
            df = dfs(v,min(cap[e],flow));
            if(df>0)
            {
                cap[e] -= df;//decrease capacity since it get added to flow
                cap[e^1] += df; //reverse edge capacity increase
                return df;
            }
        }
    }

    return 0;
}
LL dinitz()
{
   LL ans = 0;
   int df,i;
   while(bfs())
   {
   	for(int i=1;i<=nnode;i++) pro[i] = fin[i];
        while(1)//multiple s-t path in Lf(labelled graph)
        {
            df = dfs(src,INT_MAX);
            if(df>0)
                ans += df;
            else
                break;
        }
   }
   return ans;
}
int main()
{
    int t;
    int n,m,u,v,c;
    char cu,cv;
    t = 1;
    while(t--)
    {
        si(n);
        init(1,26,52);//src , sink and # (of nodes)
        for(int i=0;i<n;i++)
        {
            cin>>cu>>cv>>c;
            if(isupper(cu)) u = cu-'A'+1;
            else u = cu-'a'+27;
            if(isupper(cv)) v = cv-'A'+1;
            else v = cv-'a'+27;
            //cout<<u<<"->"<<v<<"="<<c<<endl;
            //avoid self loop in graph
            if( u != v )
                add(u,v,c);
        }
        printf("%lld\n",dinitz());

    }
    return  0;
}




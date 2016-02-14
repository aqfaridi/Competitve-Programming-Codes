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
//max nodes
#define N 53
vector< bool > visited(N);
vector< int > parent(N);
int rgraph[N][N];

int bfs(int s,int t)
{
    visited.assign(N,false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    int u,v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(v=1;v<N;v++)
        {
            if(!visited[v] && rgraph[u][v]>0)//adjacent not visited node
            {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    //if augmented path
    return (visited[t]==true);
}
int ford_fulkerson(int s,int t)
{
    int u,v,max_flow=0;
    while(bfs(s,t))
    {
        int path_flow = INF;
        //find minn bottleneck flow
        for(v = t ; v!=s ; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        //update residual capacities
        for(v = t ; v!=s ; v = parent[v])
        {
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int t;
    int n,m,u,v,c;
    char cu,cv;
    t = 1;
    while(t--)
    {
        memset(rgraph,0,sizeof rgraph);
        si(n);//edges
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
                rgraph[u][v] += c;
        }
        printf("%d\n",ford_fulkerson(1,26));

    }
    return  0;
}




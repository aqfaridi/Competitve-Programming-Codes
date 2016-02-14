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
char str[110][110];
bool visited[110][110];
int n,m;
int steps;
void DFS(int x,int y,int cnt)
{
    if(str[x][y] == '#')
    {
        if(cnt < steps)
            steps = cnt;
        return;
    }
    visited[x][y] = 1;//lock
    if(x+1<n && !visited[x+1][y] && str[x+1][y] != '*') DFS(x+1,y,cnt+1);
    if(y+1<m && !visited[x][y+1] && str[x][y+1] != '*') DFS(x,y+1,cnt+1);
    if(x-1>=0 && !visited[x-1][y] && str[x-1][y] != '*') DFS(x-1,y,cnt+1);
    if(y-1>=0 && !visited[x][y-1] && str[x][y-1] != '*') DFS(x,y-1,cnt+1);
    visited[x][y] = 0;//release
}
int main()
{
    int t;
    si(t);
    while(t--)
    {
        steps = INT_MAX ;
        memset(visited,0,sizeof visited);
        si(n);
        si(m);
       
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
    
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j] == '$')
                {             
                    DFS(i,j,0);
                    break;
                }
            }

        if(steps != INT_MAX)
            printf("%d\n",steps);
        else
            printf("-1\n");
            
    }
    return  0;
}


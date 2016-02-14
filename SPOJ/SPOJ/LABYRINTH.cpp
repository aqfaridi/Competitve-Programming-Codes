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
int n,m,maxx,call_I,call_J;
char maze[1010][1010];
void DFS(int i,int j,int cnt=0)
{
    if(cnt > maxx)
    {
        call_I = i;
        call_J = j;
        maxx = cnt;
    }
    //blocking
    maze[i][j] = '#';
    if(i+1<n && maze[i+1][j] == '.') DFS(i+1,j,cnt+1);
    if(i-1>=0 && maze[i-1][j] == '.') DFS(i-1,j,cnt+1);
    if(j+1<m && maze[i][j+1] == '.') DFS(i,j+1,cnt+1);
    if(j-1>=0 && maze[i][j-1] == '.') DFS(i,j-1,cnt+1);
    //lock releasing
    maze[i][j] = '.';
}
int main()
{
    int t;
    bool f;
    si(t);
    while(t--)
    {
        f = false;
        maxx = 0;
        si(m);
        si(n);
        for(int i=0;i<n;i++)
            scanf("%s",maze[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j] != '#')
                {
                    f = true;
                    call_I = i;
                    call_J = j;
                    break;
                }
            }
            if(f)
                break;
        }
        DFS(call_I,call_J);
        //2nd DFS with other end 
        //like longest path in tree
        DFS(call_I,call_J);

        printf("Maximum rope length is %d.\n",maxx);
    }
    return  0;
}


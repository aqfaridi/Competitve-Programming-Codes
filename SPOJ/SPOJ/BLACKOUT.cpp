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
#define clear(a)                    memset(a,0,sizeof a)

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
LL Pref[2010][2010];
LL V[2010][2010];
int main()
{
    int t,weight,value;
    int n,m,q,K,val,x1,y1,x2,y2;
    t = 1;
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&q,&K);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                si(val);
                //2D Prefix Array - Inclusion-Exclusion
                Pref[i][j] = val + Pref[i-1][j] + Pref[i][j-1] - Pref[i-1][j-1];              
            }
        }            

        for(int i=1;i<=q;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            weight = Pref[x2][y2] + Pref[x1-1][y1-1] - Pref[x1-1][y2] - Pref[x2][y1-1];
            value = (x2 - x1 + 1) * (y2 - y1 + 1);
            //1st row can be filled by 1st item
            for(int j=1;j<=K;j++)
            {
                if(weight <=j && (V[i-1][j-weight] + value >= V[i-1][j]))
                    V[i][j] = V[i-1][j-weight] + value;
                else
                    V[i][j] = V[i-1][j];
            }
        }
        pll(V[q][K]);
        pn();
    }
    return  0;
}


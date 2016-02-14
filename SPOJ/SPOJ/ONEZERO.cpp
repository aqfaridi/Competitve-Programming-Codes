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

int mod(int a,int b)
{
    if(a<b)
        return a;
    else 
        return a%b;
}
vector<bool> visited(MAX);
struct node
{
    int first;
    char second;
};

node parent[MAX];
void BFS(int n)
{
    visited.assign(MAX,false);
    queue< int  > q;  //storing remainder which act as parent for tracing path
    int rone,rtwo,v,rem;
    q.push(1);
    parent[1].first = -1;
    parent[1].second = '1';
    visited[1] = true;
    while(!q.empty())
    {
        rem = q.front();
        q.pop();
        //cout<<rem<<endl;
        //cout<<"hell";
        if(rem==0)
            break;

            // one path -'0'
            rone = ((rem%n)*(10%n))%n;
        //cout<<rone<<" "<<rtwo<<endl;    
        if(!visited[rone])
        {
            parent[rone].first = rem;
            parent[rone].second = '0';
            visited[rone] = true;
            q.push(rone);
            //cout<<rone<<endl;
        }
            //second path -'1'
           rtwo = (rone + 1)%n;
        if(!visited[rtwo])
        {
            parent[rtwo].first = rem;
            parent[rtwo].second = '1';
            visited[rtwo] = true;
            q.push(rtwo);
            //cout<<rtwo<<endl;
        }
        
    }
    
}
void trace_path(int s)
{
    if(parent[s].first == -1)
        return ;
    trace_path(parent[s].first);
    printf("%c",parent[s].second);//recursion print
}
int main()
{
    int t;
    int n;
    si(t);
    while(t--)
    {
        si(n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        BFS(n);
        printf("1");
        trace_path(0);
        pn();
    }
    return  0;
}


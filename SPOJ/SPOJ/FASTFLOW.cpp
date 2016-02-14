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

#define MAX 60010
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

//FAST IO
#define sync ios::sync_with_stdio(false);
#define untie cin.tie(NULL);
#define endll '\n'
//#define input(n) readInt(&n)

inline void readNat(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimisation
         for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
inline void readInt(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void read_string(char *str)
{
      register char c = 0;
       register int i = 0;
 
    while (c < 33)
        c = getchar_unlocked();
 
    while (c != '\n') 
    {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}
namespace IO
{
    const int SIZE = 1 << 19;
    char buff[SIZE], *p = buff + SIZE;
     char buf2[SIZE];
    int bufL2 = 0;

    inline char read_char()
    {
           if( p == buff + SIZE ) //only once check (whole i/p file)
           {
             fread( buff, 1, SIZE, stdin );
               p = buff;
        }
        return *(p++);//further invokes from buff ptr
    }
 
    inline int read_int()
    {
        char c;
        int val = 0;

        do 
        {
            c = read_char() ;
        }while( c < '-' ) ;//this while loop will continue until it finds '-' or ' ' or '\n'
        
        if( c == '-' ) 
        {
            //this means the current integer is negative
            for( c = read_char() ; c >= '0' ; c = read_char() ) 
            {
                val = val * 10 + ( c - '0' ) ;//get the integer
            }
            return - val ;//return the negative number
        }
        else 
        {
            for( ; c >= '0' ; c = read_char() ) 
            {
                val = val * 10 + ( c - '0' ) ;
            }
            return val ;//return the positive number

        }
      
    }
    inline void write_flush() 
    {
        fwrite( buf2 , sizeof( char ) , bufL2 , stdout ) ;//flushes output to stdout
        bufL2 = 0 ;//pointer returns to the beginning since output buffer array(buf2) has been flushed
    }

    inline void write_char( char c ) 
    {
        buf2[ bufL2++ ] = c ;//bufL2 points to current index in the output buffer array(buf2)  
        if( bufL2 == SIZE ) 
        {
            //array full so let's flush it
            write_flush() ;
        }
    }

    inline void write_int( LL n ) 
    {
        //recursive function to load the number to output buffer array(buf2)
        if( n >= 10 ) 
        {
            write_int( n / 10 ) ;
        }
            write_char( '0' + n % 10 ) ;
    }
    
    inline void write_Int(int n)
    {
        if(n<0)
        {
            write_char('-');
            write_flush();
            n *= (-1);
        }
        write_int(n);
    }
}

using namespace IO;

int src,snk,nnode,nedge;
int fin[5010];//stores last index of list of adjacent nodes
int dist[5010];//for labelling
int cap[MAX];//capacity of edges
int next[MAX];//pointer to next link in list
int to[MAX];//u -> v (storing v)
int q[5010];//queue
int flow[MAX];//flow
int pro[5010];
inline void init(int _src,int _snk,int n)
{
    src = _src , snk = _snk , nnode = n , nedge = 0;
    memset(fin,-1,sizeof(fin));
}
inline void add(int u,int v,int c)
{
    to[nedge] = v , cap[nedge] = c , flow[nedge] = 0 , next[nedge] = fin[u] , fin[u] = nedge++;
    //reverse edges
    to[nedge] = u , cap[nedge] = c , flow[nedge] = 0 , next[nedge] = fin[v] , fin[v] = nedge++;
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
            if(flow[e] < cap[e] && dist[v] == -1)//not yet labelled
            {
                dist[v] = dist[u] + 1;
                q[enq++] = v;
            }
        }
    }
    return (dist[snk] != -1);//not possible augmenting path
}
int dfs(int u,int flw)//find blocking flow(saturated edge) w.r.t Lf
{
    if(u==snk)//base case
        return flw;
    int v,df;
    for(int &e = pro[u];e>=0;e=next[e])//as e changes pro will change
    {
        v = to[e];
        if(flow[e]<cap[e] && dist[v] == dist[u]+1) //condtion for labelled graph
        {
            df = dfs(v,min(cap[e]-flow[e],flw));
            if(df>0)
            {
                //flow in forward edge get added
                flow[e] += df;//decrease capacity since it get added to flow
                flow[e^1] -= df; //reverse edge capacity increase
                return df;
            }
        }
    }

    return 0;
}
LL dinitz()
{
   LL ans = 0;
   int df;
   while(bfs())
   {
       for(int i=1;i<=nnode;i++) pro[i] = fin[i];
        while(1)//multiple s-t path in Lf(labelled graph)
        {
            df = dfs(src,INT_MAX); //prev pro is used 
            if(df)
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
    t = 1;
    while(t--)
    {
        n = read_int();
        m = read_int();
        init(1,n,n);//src , sink and # (of nodes)
        for(int i=0;i<m;i++)
        {
            u = read_int();
            v = read_int();
            c = read_int();
            //avoid self loop in graph
            if( u != v )
                add(u,v,c);
        }
        write_int(dinitz());
        write_flush();
        //printf("%lld\n",dinitz());

    }
    return  0;
}


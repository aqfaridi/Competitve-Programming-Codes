/*******************************
// Name : Abdul Qadir Faridi
// IPG-3rd yr
// Institute : ABV-IIITM,Gwalior

tricky:
n= 30
Case 1: AJAJAJAJAJEJEJEJEJEJUJUJUJUJUJ
60
Case 2: ABABABABABACACACACACAJAJAJAJAJAKAKAKAKAKASUSUSUSUSUTUTUTUTUT

 
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
char vowel[] = {'A','U','E','O','I'};
char consonant[] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
vector<char> v1,v2;
int v_cnt,c_cnt;
int main()
{
    int t,n;
    si(t);
    for(int tc=1;tc<=t;tc++)
    {
        v1.clear();
        v2.clear();
        c_cnt = 0;
        v_cnt = 0;
        si(n);
        for(int i=1;i<=n;i++)
        {
            if((i&1))
            {
                v1.pb(vowel[v_cnt/21]);
                v_cnt++;
            }
            else
            {
                v2.pb(consonant[c_cnt/5]);
                c_cnt++;
            }        
        }
        sort(all(v1));
        sort(all(v2));
        printf("Case %d: ",tc);
        int ptr1=0,ptr2=0;
        for(int i=1;i<=n;i++)
        {
            if((i&1))
            {
                printf("%c",v1[ptr1]);
                ptr1++;
            }
            else
            {
                printf("%c",v2[ptr2]);
                ptr2++;
            }
        }
        pn();
    
    }
    return  0;
}


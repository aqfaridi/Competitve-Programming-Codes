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
int pref[200][200],vote[200];
int main()
{
    int t;
    int n,c,v,max1,max2,pos1,pos2;
    si(t);
    while(t--)
    {
        clr(vote);
        si(c);si(v);  
        
        for(int i=1;i<=v;i++)
            for(int j=1;j<=c;j++)
                si(pref[i][j]);
        debugoff
        rep(i,v+1)
        {
            rep(j,c+1)
                cout<<pref[i][j]<<" ";
            cout<<endl;
        }
        
        for(int i=1;i<=v;i++)
            vote[pref[i][1]]++;
        
        max1 = max2 = 0;
        pos1 = pos2 = 0;
        for(int j=1;j<=c;j++)
            if(vote[j] > max1)
            {
                max1 = vote[j];
                pos1 = j;
            }
        vote[pos1] = -1;

        for(int j=1;j<=c;j++)
            if(vote[j] > max2)
            {
                max2 = vote[j];
                pos2 = j;
            }
        //cout<<max1<<" "<<max2<<endl;
        if(max1>max2 && max1 > v/2)
            printf("%d 1\n",pos1);
        else
        {
            clr(vote);
            for(int i=1;i<=v;i++)
                for(int j=1;j<=c;j++)
                {
                    if(pref[i][j] == pos1)
                    {
                        vote[pos1]++;
                        break;
                    }
                    else if(pref[i][j] == pos2)
                    {
                        vote[pos2]++;
                        break;
                    }
                
                }

            if(vote[pos1] > vote[pos2])
                printf("%d 2\n",pos1);
            else if(vote[pos2] > vote[pos1])
                printf("%d 2\n",pos2);
        }
    }
    return  0;
}


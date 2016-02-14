
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

#define gc getchar_unlocked

//macros input-output

#define si(n)                       scanf("%d",&n)
#define sll(n)                      scanf("%I64",&n)
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
#define pll(n)                      printf("%I64",n)
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

#define MAX 1000010
#define MOD 1000000007
set<int> myset; 
map<int,int> mx,my,rev_x,rev_y;
vector<int> vx,vy,vxx,vyy;
vector< pii > store;
int main()
{
    int x,y;
    for(int i=0;i<8;i++)
    {
        cin>>x>>y;
        store.pb(mp(x,y));
        mx[x]++;
        my[y]++;
    }
    map<int,int>::iterator it;
    if(mx.size() != 3 || my.size()!=3)
    {
        cout<<"ugly"<<endl;
        return 0;
    }
       
    for(it = mx.begin();it!=mx.end();it++)
    {
        //vx.pb((*it).second); 
        vx.pb((*it).first);
    }

    for(it = my.begin();it!=my.end();it++)
    {
        vy.pb((*it).first);
        //rev_y[(*it).second]=(*it).first;
    }
   
    std::sort(vx.begin(),vx.end());
    std::sort(vy.begin(),vy.end());
    int cnt = 0; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          
            if(i==1 && j==1)
                continue;
            x = vx[i] ; y = vy[j];
                
            for(int k=0;k<store.size();k++)
            {
                 if(x==store[k].first && y==store[k].second)
                         cnt++; 
            }
            
        
        }

    }
   
    if(cnt==8)
        cout<<"respectable"<<endl;
    else
        cout<<"ugly"<<endl;

/*  
  bool flag = true;
  int cnt = 0;
        if(vx[0]==2 && vx[1]==3 && vx[2]==3)
        {
             if(vy[0]==2 && vy[1]==3 && vy[2]==3)
             {
                 cout<<"hh"<<endl;
                for(int i=0;i<store.size();i++)
                {
                    if(store[i].first == rev_x[vx[0]] && store[i].second == rev_y[vy[0]])
                    {
                        flag = false;
                        break;
                    }

                }
                if(flag)
                {
                    vxx.pb(rev_x[vx[0]]);
                    vxx.pb(rev_x[vx[1]]);
                    vxx.pb(rev_x[vx[2]]);
                    vyy.pb(rev_y[vy[0]]);
                    vyy.pb(rev_y[vy[1]]);
                    vyy.pb(rev_y[vy[2]]);
                    sort(vxx.begin(),vxx.end());
                    sort(vyy.begin(),vyy.end());
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(i==1 && j==1)
                                continue;
                            x = vxx[i] ; y = vyy[j];
                            for(int k=0;k<store.size();k++)
                            {
                                if(x==store[k].first && y==store[k].second)
                                         cnt++; 
                            }
                        }
                    }
                    if(cnt == 8)
                        cout<<"respectable"<<endl;
                    else 
                        cout<<"ugly"<<endl;
                }
                else
                    cout<<"ugly"<<endl;
             }
             else
                 cout<<"ugly"<<endl;
        }
        else
            cout<<"ugly"<<endl;
           
*/
            
    

    return  0;
}

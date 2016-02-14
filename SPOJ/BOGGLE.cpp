
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
vector< pair<string,int> > v;    

bool cmp(pair<string,int> a,pair<string,int> b)
{
    return (a.second)<(b.second);
}
int rule[]={0,1,1,1,1,2,3,5,11};
int main()
{
    int n,size;
    char ch;
    string str,s;
    si(n);
    int arr[n+1];
    ch = getchar();
    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        stringstream mystr(str);
        while(mystr >> s)
        {
            //cout<<s<<endl;
            v.pb(mp(s,i));
        }
    }
    sort(all(v));
    int k;
    size = v.size();

/******************************************************** 
    for(int j=0;j<size;j++)
    {
        //if(v[j].first!=v[j+1
        cout<<v[j].first<<" "<<v[j].second<<endl;
            
    }
********************************************************/  
    for(int i=0;i<v.size()-1;i++)
    {
        k = i;
        while((i+1<v.size()) && (v[i].first).compare(v[i+1].first)==0)
        {
            //cout<<v[i].first<<" "<<v[i+1].first<<endl;
            i++;
        }
        if(i>k)
        {
            //cout<<k<<" "<<i<<endl;
            v.erase(v.begin()+k,v.begin()+i+1);
            i = k-1;
        }
      
    }
    size = v.size();
    memset(arr,0,sizeof(arr));
    //sort(v.begin(),v.end(),cmp);
    int maxx = 0,cnt = 0,len;
    for(int j=0;j<size;j++)
    {
        len = (v[j].first).length();
        arr[v[j].second] += ( len > 7)?rule[8]:rule[len];
        //cout<<v[j].first<<" "<<v[j].second<<endl;        
    }
    pi(*max_element(arr,arr+n+1));
    pn();
    
    return  0;
}

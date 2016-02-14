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
char str[100000];    
int main()
{
    string ans,temp,chotu_str;
    int len,r,sum,lastdig;
    map<string,int> my;
    map<int,string> rev;
    my["010"] = 1;
    my["093"] = 2;
    my["079"] = 3;
    my["106"] = 4;
    my["103"] = 5;
    my["119"] = 6;
    my["011"] = 7;
    my["127"] = 8;
    my["107"] = 9;
    my["063"] = 0;
    

    rev[1] = "010";
    rev[2] = "093";
    rev[3] = "079";
    rev[4] = "106";
    rev[5] = "103";
    rev[6] = "119";
    rev[7] = "011";
    rev[8] = "127";
    rev[9] = "107";
    rev[0] = "063";
    while(1)
    {
        sum = 0;
        scanf("%s",str);
        if(!strcmp(str,"BYE"))
            break;
        printf("%s",str);
        char *ch = strtok(str,"+=");
        while(ch!=NULL)
        {
            temp = ch;
            r = 0;
            for(int i=0;i<temp.length();i+=3)
            {
                chotu_str = temp.substr(i,3);
                r = r*10 + my[chotu_str];
            }
            sum += r;
            ch = strtok(NULL,"+=");
        }
        //len = (int)ceil(log10(sum));
        ans = "";
        while(sum>0)
        {
            lastdig = sum%10;
            ans = rev[lastdig] + ans;
            sum/=10;
        }

        cout<<ans<<endl;
    }
    return  0;
}


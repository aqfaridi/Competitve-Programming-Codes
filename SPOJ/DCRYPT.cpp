
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
int main()
{
    int t,l;
    string str;
    int key;
    char ch;
    cin>>t;
    while(t--)
    {
        cin>>key;
        cin>>str;
        l = str.length();
        for(int i=0;i<l;i++)
        {
            if(str[i]=='.')
            {
                cout<<' ';
                continue;
            }
            if(key<=25)
            {
                if(isLowerCase(str[i]))
                {
                    if(str[i]+key > 122)
                        cout<<(char)((str[i]+key)-122 + 97 -1);  
                    else
                        cout<<(char)(str[i]+key);
                }
                else
                {
                    if(str[i]+key > 90)
                        cout<<(char)((str[i]+key)-90 + 65 -1);  
                    else
                        cout<<(char)(str[i]+key);
                }
            }
            else
            { 
                if(isLowerCase(str[i]))
                {
                    if(str[i]+key%26 > 122)
                    {
                        ch = (str[i]+key%26)-122 + 97 -1;  
                        //cout<<(int)ch<<endl;
                        cout<<toUpperCase(ch);
                    }
                    else
                    {
                        ch = str[i]+key%26;
                        cout<<toUpperCase(ch);
                    }
                }
                else
                {
                    if(str[i]+key%26 > 90)
                    {
                        ch = (str[i]+key%26)-90 + 65 - 1; 
                        cout<<toLowerCase(ch);
                    }
                    else
                    {
                        ch = (str[i]+key%26);
                        cout<<toLowerCase(ch);
                    }
                }
            }

        }
        cout<<endl;
    }
    return  0;
}

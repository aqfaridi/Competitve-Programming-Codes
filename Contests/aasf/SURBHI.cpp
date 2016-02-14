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
#define    forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define pn()                        printf("\n")
#define pi(n)                       printf("%d",n)
#define pll(n)                      printf("%I64",n)
#define pd(n)                       printf("%lf",n)
#define ps(str)                     printf("%s",str)

//macros stl

#define mp                          make_pair
#define pb                          push_back
#define fill(a,v)                   memset(a,v,sizeof a)
#define all(x)                      x.begin(),x.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
#define clr(a)                      memset(a,0,sizeof a)

using namespace std;

//typedef

typedef long long LL;
typedef pair<int,int> pii;

#define MAX 1000010
#define MOD 1000000007
    
int main()
{
    int t;
    int n,l,k;
    char str[MAX];
 
    si(t);
    while(t--)
    {
        scanf("%s",str);
        l = strlen(str);
        for(int i=0;i<l;i++)
        {
            if(str[i] == '[')
            {
                i++;
                k=0;
                char sub[MAX];
                while(i<l && str[i]!=']')
                    sub[k++] = str[i++];
                sub[k] = '\0';
                reverse(sub,sub+k);
                cout<<sub;
            }
            else
               
                cout<<str[i];
        }
        cout<<endl;
    }
    return  0;
}


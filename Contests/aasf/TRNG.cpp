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
int area(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return (int)abs( x1*(y2-y3) +y1*(x3-x2) + (x2*y3-x3*y2));
}
int main()
{
    int t,n;
    int x1,x2,x3,y1,y2,y3;
    int p1,q1,p2,q2,p3,q3;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;  
        cin>>p1>>q1>>p2>>q2>>p3>>q3;
        int ans = area(x1,y1,x2,y2,x3,y3);
        int ans1 = area(p1,q1,p2,q2,p3,q3);
        if(ans == ans1)
            cout<<0<<endl;
        else if (ans>ans1)
            printf("1 %.2lf\n",(ans/2.0));
        else
            printf("2 %.2lf\n",(ans1/2.0));
    }
    return  0;
}

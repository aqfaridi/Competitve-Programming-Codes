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
#define rep(i,n)                    for(i,0,n) 
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
#define clear(a)                    memset(a,0,sizeof a)

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
int main()
{
    int t,q,save_q;
    int arr[MAX];
    LL n,energy,sum,maxx,cnt,actual_cnt;
    map<char,int> m;
    m['G'] = 0;
    m['R'] = 1;
    m['Y'] = 2;
    m['B'] = 3;
    m['O'] = 4;
    string str;
    int cases = 0;
    bool b;
    si(t);
    while(t--)
    {
        cases++;
        maxx = 0;
        cnt = 0;
        actual_cnt = 0;
        cin>>energy>>str;
        int l = str.length();
        arr[0] = 0;
        forr(i,1,l)
        {
            arr[i] = abs(m[str[i]] - m[str[i-1]]);
            //cout<<arr[i]<<" ";
        }
        cout<<endl;
        q = 0;
        sum = 0 ;
        save_q = 0;
        b = false;
        for(int i=0;i<l;i++)
        {
            sum += arr[i];
            if(sum > energy)
            {
                while(sum>energy && q<l)
                {
                    sum -= arr[q];
                    q++;
                }
            }
            
            cnt = (i+1) - q;//interval of sum
            if(cnt == actual_cnt)
                b = true;
            if(cnt > actual_cnt || (cnt==actual_cnt && sum < maxx))
            {                   
                maxx = sum;
                actual_cnt = cnt; 
                save_q = q;
            }
            //cout<<i<<" "<<q<<" ";
            //cout<<cnt<<" ";
            //cout<<actual_cnt<<endl;
        }
        printf("Scenario #%d: ",cases);
        if(save_q!=0)
            pll(actual_cnt + 1);
        else if(save_q==0 && b)
            pll(actual_cnt +1);
        else if(save_q==0)
            pll(actual_cnt);
        pn();
    }
    return  0;
}


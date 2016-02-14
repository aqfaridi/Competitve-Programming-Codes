
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
#define MAX 100010
#define MOD 1000000007
   
int input[MAX];
int mod;
vector<pair<LL,int> > cumm;
pair<int,pair<int,int> > extendedEuclid(long long a,long long b)
{

    long long xLast = 1,yLast = 0,q,r,m,n;
    long long x = 0,y = 1;
    while(b!=0)
    {
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;
        xLast = x ; yLast = y;
        x = m ; y = n;
        a = b; b = r;
    }
    return make_pair(a,make_pair(xLast,yLast));
}
long long modInverse(long long a,long long m)
{
        return (extendedEuclid(a,m).second.first + m)%m; 
}

LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result = (result*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return result%mod;
}
int main()
{
    int t,n,q;
    int l,r,rem=0;
    int num;
    LL ans,Nr,Dr;

    cin>>n;
    cumm.push_back(make_pair(1,0));
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        ans = cumm[i-1].first * num;
        if( ans > MOD )
            rem += ans / MOD;
        if(rem != 0)
            cumm[i-1].second = rem;
        cumm.pb(mp(ans % MOD , num*cumm[i-1].second));     
        cout<<cumm[i].first<<" "<<cumm[i].second<<endl;
    }

    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&l,&r);
        cin >> mod;
        if(mod == 1)
        {
            cout<<0<<endl;
            continue;
        }
        Nr = cumm[r].first % mod;
        Dr = cumm[l-1].first % mod;
        if(cumm[r].second !=0)
            Nr = (Nr + (MOD * cumm[r].second)%mod)%mod;
        if(cumm[l-1].second !=0 )
            Dr = (Dr + (MOD * cumm[l-1].second)%mod)%mod;             
        cout<<"Nr="<<Nr<<endl;
        cout<<"Dr="<<Dr<<endl;
        LL phi = mod;     
        int nn = mod;
        for(int i=2;i*i <= nn ;i++)
        {
            if(nn%i == 0)
                phi -= phi/i;
                                              
            while(nn%i == 0)
                nn /= i;
        }
        if(nn>1)
            phi -= phi/nn;
        //cout<<"phi="<<phi<<endl;
        //cout<<modInverse(Dr,phi-1)<<endl;
        
        Nr = (Nr * expo(Dr,mod-2) % mod) % mod;
        //cout<<ans<<endl;
        cout << Nr << endl;
    } 
    return 0;
}


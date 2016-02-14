#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    
#define MAX 3000010
#define MaX 1000010
#define MOD 1000000
int S[MAX],sq[MaX];
int maxx;
void precompute(LL n,LL a,LL b,LL c,LL d)
{
    LL odd = 0 ,even = 0;
    int cnt[MaX] = {0};
    S[0] = d;
    maxx = d;
    cnt[S[0]]++;
    for(int i=1;i<n;i++)
    {
        S[i] = ((a*S[i-1]*S[i-1]) + (b*S[i-1]) + c)%MOD;
        print(S[i]);
        cnt[S[i]]++;
        if(S[i] > maxx)
            maxx = S[i];
    }

    bool f = 1;
    for(LL i=maxx;i>=0;i--)
    {
        if((cnt[i]&1))
        {
            if(f)
                odd += i;
            else
                even += i;
            f = 1-f;;
        }
    }
    printf("%lld\n",(LL)abs(odd - even));
}
int main()
{
    int t;
    LL n,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
        precompute(n,a,b,c,d);
    }
    return 0; 
}

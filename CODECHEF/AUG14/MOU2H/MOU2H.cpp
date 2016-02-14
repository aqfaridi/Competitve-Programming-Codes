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
#include <climits>
#include <cassert>

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
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 1000010
#define MOD 1000000009
int dp[MAX],lpos[MAX*9];
int str[MAX];
int solve(int n)
{
    dp[0] = 1; dp[1] = 2;
    lpos[str[1]] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = (2*dp[i-1])%MOD;
        if(lpos[str[i]] != 0)
            dp[i] = (dp[i] - dp[lpos[str[i]]-1])%MOD;
        lpos[str[i]] = i;
    }
    for(int i=1;i<=n;i++)   lpos[str[i]] = 0;

    return (dp[n]-1+MOD)%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,hp,hc,d,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>hp;
        for(int i=1;i<n;i++)
        {
            cin>>hc;
            d = hc - hp;
            if(d <= 0)
                d += 8*MAX;
            str[i] = d;
            hp = hc;
        }
        cout << solve(n-1) << endl;
    }
    return 0; 
}

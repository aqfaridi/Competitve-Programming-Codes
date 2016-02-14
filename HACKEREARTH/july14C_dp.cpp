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

#define MAX 100010
#define MOD 1000000007
int n,m,K;
double dp[60][10010];
double solve()
{
    dp[0][0] = 1;

    for(int idx=1;idx<=n;idx++)
        for(int k=0;k<=K;k++)
            for(int i=1;i<=n;i++)
                if(k-i >= 0)
                    dp[idx][k] += (1.0/n) * dp[idx-1][k-i];

    return dp[m][K];
}
int main()
{
    int t;
    double ans;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>K;   
        memset(dp,0,sizeof dp);
        ans = solve();
        if(ans == 0.000)
        {
            cout<<"0.000 0"<<endl;
            continue;
        }
        int cnt = 0;
        while(ans < 1)
        {
            ans *= 10;
            cnt++;
        }
        cout << setprecision(3) << fixed << ans ;
        cout <<" " << cnt << endl;
    }
    return 0; 
}

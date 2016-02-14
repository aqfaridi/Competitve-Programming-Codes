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
    

#define debug                       if(1)
#define debugoff                    if(0)    
#include <climits>
#define MAX 110
#define MOD 1000000007
int dp[MAX][MAX];
int store[MAX];
vector<int> p1,p2;
LL solve(int s,int a,int b)
{
    LL ans = LONG_MAX;
    sort(store,store+s);
    LL min1,min2,cost;
    for(int i=0;i<(1<<s);i++)
    {
        p1.clear();p2.clear();
        p1.pb(a);p2.pb(b);
        for(int j=0;j<s;j++)
        {
            if(i & (1<<j))
                p1.pb(store[j]);            
            else
                p2.pb(store[j]);
        }
        min1 = min2 = LONG_MAX/10 ;
       
        do
        {
            cost = 0;
            for(int k=1;k<p1.sz;k++)
                cost += dp[p1[k-1]][p1[k]];
            min1 = min(min1,cost);
        }while(next_permutation(p1.begin()+1,p1.end()));

        
        do
        {
            cost = 0;
            for(int k=1;k<p2.sz;k++)
                cost += dp[p2[k-1]][p2[k]];
            min2 = min(min2,cost);
        }while(next_permutation(p2.begin()+1,p2.end()));
        ans = min(ans,min1+min2);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,s,a,b,c;
    memset(dp,63,sizeof dp);
    rep(i,MAX)
        dp[i][i] = 0;
                
    cin>>n>>m;
    rep(i,m)
    {
        cin>>a>>b>>c;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    rep(k,n)
        rep(i,n)
            rep(j,n)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
    cin>>s;
    rep(i,s)
        cin>>store[i];
    cin>>a>>b;//location of both frnd

    cout<<solve(s,a,b)<<endl;

    return 0; 
}

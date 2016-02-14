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

#define MAX 1010
#define MOD 1000000007
int mem[MAX][MAX];
int w[MAX],cumm[MAX];
int n,m,minn=INT_MAX;

int solve3(int idx,int prev)
{
    int sum = 0;
    if(idx == m)
    {
        sum = 0;
        for(int i=prev+1;i<=n;i++)
            sum += w[i];
        return sum;
    }

    int& res = mem[idx][prev];
    if(res != -1)    return res;

    res = INT_MAX;
    sum = 0;
    for(int i=prev+1;i<=n;i++){
        sum += w[i];
        res = min(res,max(sum , solve3(idx+1,i)));
    }
    return res;
}
int dp[MAX][MAX];
int iterative()
{
    for(int i=1;i<=n;i++)
        dp[1][i] = cumm[i];

    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j++){
            dp[i][j] = 1e9;
            for(int k=i-1;k<=j;k++)
                dp[i][j] = min(dp[i][j],max(cumm[j]-cumm[k],dp[i-1][k]));
        }
    }

    for(int i=0;i<=m;i++){
    for(int j=1;j<=n;j++)
        cout<<dp[i][j]<<" ";
    cout<<endl;
    }

    return dp[m][n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>m;
    cin>>n;
    for(int i=1;i<=n;i++) {   cin>>w[i];cumm[i] = cumm[i-1] + w[i];}
    /*
    for(int i=0;i<=n;i++)
        for(int j=i-1;j<=n;j++)
        {
            for(int k=i+1;k<=j;k++)
                cumm[i][j]  += w[k];
        }
    */
    //memset(cost,0,sizeof(cost));
    memset(mem,-1,sizeof mem);
    cout<<solve3(1,0)<<endl;
    cout<<iterative()<<endl;
    
    return 0; 
}

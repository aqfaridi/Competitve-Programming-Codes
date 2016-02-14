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
int cut[MAX],mem[MAX];
int solve(int n)
{
    if(n == 0)  return 0;

    int& res = mem[n];
    if(res != -1)   return res;

    res = INT_MIN;
    for(int i=1;i<=n;i++)
        if(n-i >= 0)
            res = max(res,cut[i] + solve(n-i));
    return res;
}
int n;
int mem2[MAX][MAX];
int solve_my(int idx,int prev)
{
    if(idx == n+1)  return 0;

    int& res = mem2[idx][prev];
    if(res != -1)   return res;
    

    //cut at idx
    res = cut[idx-prev] + solve_my(idx+1,idx);
    //no cut at idx
    res = max(res,solve_my(idx+1,prev));
    return res;
}
int dp[MAX];
int iterative()
{
    dp[1] = cut[1];
    for(int i=2;i<=n;i++){
        dp[i] = cut[i];
        for(int j=1;j<i;j++)
            dp[i] = max(dp[i],dp[j]+dp[i-j]);
    }
    return dp[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>cut[i];
    memset(mem,-1,sizeof(mem));
    memset(mem2,-1,sizeof mem2);
    cout<<iterative()<<endl;
    //cout<<solve_my(1,0)<<endl;    
    return 0; 
}

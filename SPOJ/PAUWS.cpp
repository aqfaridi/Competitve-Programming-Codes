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

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
int dp[MAX];
void solve(string str,int n)
{
    dp[0] = 1;
    if(str[0] != str[1])//pair
        dp[1] = 4;
    else
        dp[1] = 3;

    for(int i=2;i<n;i++)
    {
        if(str[i] != str[i-1])//pair
            dp[i] = max(dp[i-2]+4,dp[i-1]+1);
        else
            dp[i] = max(dp[i-2]+3,dp[i-1]+1);
    }
    cout<<dp[n-1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>str;
        solve(str,n);
    }
    return 0; 
}

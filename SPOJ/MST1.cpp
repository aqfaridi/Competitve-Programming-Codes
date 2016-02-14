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
#include <climits>
#include <cassert>
#define MAX 20000001
#define MOD 1000000007
int dp[MAX];
void solve()
{
    int m;
    dp[2] = dp[3] = 1;
    for(int i=4;i<MAX;i++)
    {
        m = dp[i-1];
        if(i%2 == 0)
            m = min(m,dp[i/2]);
        if(i%3 == 0)
            m = min(m,dp[i/3]);
        dp[i] = m + 1;
    }
}
int main()
{
    solve();
    ios::sync_with_stdio(false);
    int t,n,steps,cases;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>n;
        cout<<"Case "<<cases<<": "<<dp[n]<<endl;
    }
    return 0; 
}

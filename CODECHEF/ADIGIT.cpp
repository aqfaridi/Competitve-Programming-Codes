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

#define MAX 100020
#define MOD 1000000007
int dp[10][MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q,l,idx;
    LL cnt,ans;
    string str;
    cin>>l>>q;
    cin>>str;
    rep(i,l)
    {
        for(int j=0;j<10;j++)
            dp[j][i] = dp[j][i-1];
        dp[str[i]-'0'][i]++;
    }
    rep(i,q)
    {
        ans = 0;
        cin>>idx;
        idx -= 1;
        for(int i=0;i<10;i++)
        {
            cnt = dp[i][idx];
            ans += cnt*(int)abs(str[idx]-'0' - i);
        }
        cout<<ans<<endl;
    }
    return 0; 
}

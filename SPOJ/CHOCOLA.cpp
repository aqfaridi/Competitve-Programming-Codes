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
bool cmp(int a,int b)
{
    return (a>b);
}
int x[1010],y[1010],r,c;
LL dp[1010][1010];

LL solve()
{
    dp[0][0] = 0;
    for(int j=1;j<c;j++)    dp[0][j] = dp[0][j-1] + y[j];
    for(int i=1;i<r;i++)    dp[i][0] = dp[i-1][0] + x[i];

    for(int i=1;i<r;i++)
        for(int j=1;j<c;j++)
            dp[i][j] = min(dp[i-1][j]+(j+1)*x[i],dp[i][j-1]+(i+1)*y[j]);
    return dp[r-1][c-1];
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        for(int i=1;i<r;i++)
            cin>>x[i];
        for(int j=1;j<c;j++)
            cin>>y[j];

        sort(x+1,x+r,cmp);
        sort(y+1,y+c,cmp);

        cout<<solve()<<endl;
    }
    return 0; 
}

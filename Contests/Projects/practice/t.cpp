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
int tmp[1010][1010];
int dp[2][1010];
int m,n,x,y;
LL mn=(1<<20);
LL fun(int i , int j , int col){
    if(i>n)return (1<<26);
    
    if(j == m)
    {
        cout<<"ff "<<i<<" "<<j<<" "<<col<<endl;
        int width = j-i+1;
        if(width >=x && width <=y)
        {
            cout<<"hello="<<dp[col][j]-dp[col][i-1]<<endl;
            return (dp[col][j]-dp[col][i-1]);
        }
        else
            return (1<<20);
    }

    for(int siz = x; siz<= y ; siz++){
        cout<<"tt "<<i<<" "<<j<<" "<<dp[col][j]-dp[col][i-1]<<endl;
        mn = min(mn,fun(j+1,min(m,j+siz),1-col)+(dp[col][j]-dp[col][i-1]) + 0LL);
        cout<<"mn="<<mn<<endl; 
        //cout<<i<<" "<<j<<" "<<mn<<endl;
    }
    return mn;
}
int main()
{
    ios::sync_with_stdio(false);
    int cnt,ans = (1<<20) , mn1 = (1<<20) , mn2 = (1<<20);
    char ch;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch;
            if(ch == '#')
               tmp[i][j] = 1;
            else
                tmp[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        cnt = 0;
        for(int j=1;j<=n;j++){
            if(tmp[j][i] == 1)
                cnt++;
        }
        dp[0][i] = dp[0][i-1]+cnt;
    }
    for(int i=1;i<=m;i++){
        cnt = 0;
        for(int j=1;j<=n;j++){
            if(tmp[j][i] == 0)
                cnt++;
        }
        dp[1][i] = dp[1][i-1]+ cnt;
    }
    for(int i=1;i<=m;i++)cout<<dp[0][i]<< " ";cout<<endl;
    for(int i=1;i<=m;i++)cout<<dp[1][i]<< " ";cout<<endl;
    for(int i=x;i<=y;i++){

        cout<<"i " << i<< " " << mn1 << endl;
        mn = (1<<20);
        mn1 = fun(1,i,0);
        cout<<"i " << i<<" " << mn2 << endl;
        mn = (1<<20);
        mn2 = fun(1,i,1);
        ans = min(mn1,mn2);
    }
    cout<<ans<<endl;
    return 0; 
}

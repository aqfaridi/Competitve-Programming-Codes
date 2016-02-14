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

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > tri;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector< pii > vpii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define fore(i,a,b)                 for(int i=a;i<=b;i++)
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
LL arr[100010];
LL mem[100010][2];
int n;
LL solve(int idx,int turn){
    
    if(idx == n)    return 0;
    
    LL& res = mem[idx][turn];
    if(res != -1)   return res;
    
    if(turn == 1)   res = INT_MAX;
    LL sum = 0;
    
    for(int i=0;i<4 && (idx+i < n);i++){
        sum += arr[idx+i];
        //trace3(idx,turn,res);
        if(turn == 0)
            res = max(res,sum + solve(idx+i+1,1-turn));
        else
            res = min(res,sum + solve(idx+i+1,1-turn));
    }
    
    return res;
}
LL dp[100010];
int main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>n;
        rep(i,n)    cin>>arr[i];   
        cout<<solve(0,0)<<endl;
        LL maxx = 0;
        for(int i=0;i<n;i++)
        {
            cout<<mem[i][0]<<" ";
            maxx = max(maxx,mem[i][0]);
        }
        cout<<maxx<<endl;
        LL sum = 0;
        for(int i=0;i<min(4,n);i++){
            sum += arr[i];
            dp[i] = sum;
        }
        
        for(int i=4;i<n;i++){
            dp[i] = dp[i-1];
            if(i-5 >= 0)
            dp[i] = max(dp[i],arr[i] + dp[i-5]);
        }
        
        cout<<dp[n-1]<<endl;
    }
    

	return 0;
}
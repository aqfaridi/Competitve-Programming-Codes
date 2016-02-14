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
#define INF 522133279
#define MOD 1000000007
int arr[MAX],dp[MAX],min_idx[10],min_sol[10];
int solve(int n)
{
    memset(dp,31,sizeof(dp));
    memset(min_sol,31,sizeof(min_sol));
    memset(min_idx,31,sizeof(min_idx));
    min_sol[arr[0]] = dp[0] = min_idx[arr[0]] = 0;

    int loop = 10;
    while(loop--)
    {
        for(int i=1;i<n;i++)
        {
            dp[i] = min(dp[i-1]+1,min_sol[arr[i]]+1);
            if(dp[i] < min_sol[arr[i]])
            {
                min_sol[arr[i]] = dp[i];
                min_idx[arr[i]] = i;
            }
        }

        for(int i=n-2;i>=1;i--)
        {
            dp[i] = min(dp[i+1]+1,min_sol[arr[i]]+1);
            if(dp[i] < min_sol[arr[i]])
            {
                min_sol[arr[i]] = dp[i];
                min_idx[arr[i]] = i;
            }
        }

        for(int i=1;i<n-1;i++)
        {
            dp[i] = min(min(dp[i],min(dp[i-1]+1,dp[i+1]+1)),min_sol[arr[i]]+1);
            if(dp[i] < min_sol[arr[i]])
            {
                min_sol[arr[i]] = dp[i];
                min_idx[arr[i]] = i;
            }
        }
    }
    //for final ans
    
    if(min_idx[arr[n-1]] != (n-1)) 
        dp[n-1] = min(dp[n-1],min(dp[n-2]+1,min_sol[arr[n-1]]+1));
    else
        dp[n-1] = min(dp[n-1],dp[n-2]+1);

    return dp[n-1];
}
int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    int l = str.length();
    for(int i=0;i<l;i++)
        arr[i] = str[i] - '0';
  
    if(l== 1 || l==2)
    {
        cout<<l-1<<endl;
        return 0;
    }
    cout<<solve(l)<<endl;
    return 0; 
}

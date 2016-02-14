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
#include <numeric>

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

int solve(int idx,int prev)
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
        res = min(res,max(sum , solve(idx+1,i)));
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

    return dp[m][n];
}
bool binary(int mid)
{
    int sum = 0,workers=1;
    for(int i=1;i<=n;i++)
    {
        if(sum + w[i] <= mid)
            sum += w[i];
        else{
            workers++;
            sum = w[i];
        }
    }

    return (workers <= m); 
}
int solve_bsearch()
{

    int low = *max_element(w,w+n+1);
    int high = accumulate(w,w+n+1,0);
    int mid;
    while(low < high)
    {
        mid = (low + high)/2;
        if(binary(mid))
            high = mid;
        else
            low = mid+1;
    }

    return low;
}
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>m;
        for(int i=1;i<=n;i++) {   cin>>w[i];cumm[i] = cumm[i-1] + w[i];}
        
        ans = solve_bsearch();
        //memset(mem,-1,sizeof mem);
        //ans = solve(1,0);        
        //cout<<iterative()<<endl;
        //cout<<ans<<endl; 
        int k=0,sum = 0;
        for(int i=n;i>=1;i--){
            if(i == m-1){
                for(int j=i;j>=1;j--){
                    arr[k++] = -1;
                    arr[k++] = w[j];
                }
                break;
            }
            else if(sum + w[i] <= ans){
                arr[k++] = w[i];
                sum += w[i];
            }
            else{
                m--;
                if(i == m){                    
                    for(int j=i;j>=1;j--){
                        arr[k++] = -1;
                        arr[k++] = w[j];
                    }
                    break;
                }
                sum = w[i];
                arr[k++] = -1;
                arr[k++] = w[i];
            }
        }
        for(int i=k-1;i>=0;i--){
            if(arr[i] == -1)
                cout<<"/";
            else
                cout<<arr[i];
            cout<<" ";
        }
        cout<<endl;

    }

    return 0; 
}

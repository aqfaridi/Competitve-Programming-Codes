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
int cost[MAX],w[MAX],cumm[MAX][MAX];
int n,m,minn=INT_MAX;
void solve2(int idx)
{
    if(idx == n)
    {
        for(int i=0;i<m;i++)
            cout<<cost[i]<<" ";
        cout<<endl;
        minn = min(minn,*max_element(cost,cost+m));
        return;
    }

    for(int i=0;i<m;i++){
        cost[i] += w[idx];
        solve2(idx+1);
        cost[i] -= w[idx];
    }
}
int solve(int idx,int prev)
{
    trace2(idx,prev);
    if(idx == m+1)
    {
        for(int i=1;i<=m;i++)
            cout<<cost[i]<<" ";
        cout<<endl;
        minn = min(minn,*max_element(cost,cost+m+1));
        return minn;
    }

    int& res = mem[idx][prev];
    if(res != -1)   return res;

    if(prev == n)
        res = solve(m+1,n);

    for(int i=prev+1;i<=n;i++){
            if(idx == m)
                cost[idx] = cumm[prev+1][n];
            else
                cost[idx] = cumm[prev+1][i];
            trace3(idx,prev,i); 
            res = solve(idx+1,i);
    }

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>m;
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>w[i];

    for(int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
                cumm[i][j]  += w[k];
        }

    memset(cost,0,sizeof(cost));
    memset(mem,-1,sizeof mem);
    cout<<solve(1,0)<<endl;
    

    return 0; 
}

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

#define MAX 1020
#define MOD 1000000007
vector<int> adjList[MAX];
int visited[MAX];
int dp[MAX][2];
int DFS(int node,int parent,int color)
{
    int size = adjList[node].size(),r0=0,r1=1;
    int& res = dp[node][color];
    if(res != -1)   return dp[node][color];
    res = 0;
  
    visited[node] = 1;

    if(color==1)//parent is colored
    {
        for(int i=0;i < size;i++)
        {
            if(adjList[node][i] != parent)
            {  
                r0 += DFS(adjList[node][i],node,0);
                r1 += DFS(adjList[node][i],node,1);      
            }
        }
        res = min(r0,r1);
    }
    else
    {
        for(int i=0;i < size;i++)
            if(adjList[node][i] != parent)
            {
                //cur node is included in r1
                r1 += DFS(adjList[node][i],node,1);
            }
        res = r1;
    }
   
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,u,v,r0=0,r1=1,size,ans = 0;
    
    memset(dp,-1,sizeof dp);
    memset(visited,0,sizeof(visited));
   
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            size = adjList[i].size();
            for(int j=0;j<size;j++)
                r0 += DFS(adjList[i][j],i,0);
            
            for(int j=0;j<size;j++)
                r1 += DFS(adjList[i][j],i,1);
            
            //trace2(r0,r1);       
            ans += min(r0,r1);
            r0 = 0;r1 = 1;
        }
    } 
    cout << ans << endl;

    return 0; 
}

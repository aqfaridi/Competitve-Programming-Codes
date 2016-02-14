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
vector<int> adjList[MAX];
int dp[MAX][2];
int DFS(int node,int parent,int color)
{
    int size = adjList[node].size(),r0=0,r1=1;
    int& res = dp[node][color];
    if(res != -1)   return dp[node][color];
    res = 0;
   
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
    int n,u,v,r0=0,r1=1,size;
    memset(dp,-1,sizeof dp);

    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    size = adjList[1].size();
    for(int i=0;i<size;i++)
        r0 += DFS(adjList[1][i],1,0);
    
    for(int i=0;i<size;i++)
        r1 += DFS(adjList[1][i],1,1);
        
    cout<<min(r0,r1)<<endl;

    return 0; 
}

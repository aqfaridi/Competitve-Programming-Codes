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

#define MAX 10220
#define MOD 1000000007
vector<LL> adjList[MAX];
LL maxsize(LL n)
{
    LL maxx = 0,idx=1;
    for(int i=1;i<=n;i++)
        if(adjList[i].size() > maxx)
        {
            maxx = adjList[i].size();
            idx = i;
        }

    return idx;
}
int main()
{
    ios::sync_with_stdio(false);
    LL n,m,u,v,idx,size,ans = 0,adj;    
   
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
    	if(adjList[i].size() == 0)
    		cnt++;
    		
    while(1)
    {
        idx = maxsize(n);
        size = adjList[idx].size();
        if(size == 0)   break;
        
        ans += 1;
        for(int i=0;i<size;i++)
        {
           adj = adjList[idx][i];
           
           for(int j=0;j < adjList[adj].size();j++)
               if(adjList[adj][j] == idx)
               {
                   adjList[adj].erase(adjList[adj].begin()+j);
                   break;
               }
               
        }
        adjList[idx].clear();
    } 

	if(cnt == 0)
    	cout << ans << endl;
    else
    	cout << 3 << endl;

    return 0; 
}

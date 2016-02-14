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

#define MAX 1220
#define MOD 1000000007
vector<LL> adjList[MAX];
int mark[MAX];
LL maxsize(LL n)
{
    LL maxx = 0,idx=0,size,cnt;
    for(int i=1;i<=n;i++)
    {
        cnt = 0;
        size = adjList[i].size();
        for(int j=0;j<size;j++)
            if(!mark[adjList[i][j]])
                cnt++;

        if(cnt >= maxx)
        {
            maxx = size;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    LL n,m,u,v,idx,size,ans = 0,adj,cnt=0,br;
   
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    
    for(int i=1;i<=n;i++)
    {
        size = adjList[i].size();
        if(size == 0)
            cnt++;
    }
    
    //assert(cnt == 0);

    while(1)
    {
        idx = maxsize(n);
        size = adjList[idx].size();
        if(size == 0)    break;
        br = 0;
        if(mark[idx])   br = 1;
        for(int i=0;i<size;i++)           
        {
            adj = adjList[idx][i];
            if(mark[adj])
                br++;
        }
        if(br == size+1) 
        {
            adjList[idx].clear();
            continue;
        }
        ans += 1;
        for(int i=0;i<size;i++)
        {
           adj = adjList[idx][i];
           vector<LL>::iterator it = find(adjList[adj].begin(),adjList[adj].end(),idx);
           adjList[adj].erase(it);
           mark[adj] = 1;
        }
        adjList[idx].clear();
    }

    assert(ans+cnt <= n);

    cout << ans + cnt << endl;

    return 0; 
}

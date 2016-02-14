#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
vector<int> adjList[MAX];
int n;
int match[MAX];
bool seen[MAX];
bool bpm(int u)
{
    int size = adjList[u].size();
    //try every job
    for(int v=0;v<size;v++)
    {
        if(!seen[v])
        {
            seen[v] = true;
            if(match[v] < 0 || bpm(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM()
{
    memset(match,-1,sizeof(match));
    int cnt=0;
    for(int u=0;u<n;u++)
    {
        memset(seen,0,sizeof(seen));
        if(bpm(u))
            cnt++;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,m,u,v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            adjList[i].clear();

        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout<<maxBPM()<<endl;
    }
    return 0;
}

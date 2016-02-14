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

#define MAX 50020
#define MOD 1000000007    
bool open[MAX],visited[MAX];
vector< int > v[MAX];
void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        visited[i] = 0;
        open[i] = 0;
        v[i].clear();
    }
}
LL total,pairs,cnt,totcnt;

void DFS(int node)
{
    visited[node] = 1;
    cnt++;
    if(open[node])        
        pairs++;
    

    int u,size = v[node].size();
    for(int i=0;i<size;i++)
    {
        u = v[node][i];
        if(!visited[u])            
        {
            DFS(u);  
            if(open[u])
                open[node] = 1;
        }
    }

    if(!open[node])
        cnt--;
}
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,m,a,b;
    t = 1;
    while(t--)
    {
        cin>>n>>m;
        reset(n);
        for(int i=1;i<=n;i++)
            cin>>open[i];
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && open[i])
            {
                pairs = 0;
                cnt = 0;
                DFS(i);
                total += (pairs*(pairs-1)/2);
                if(pairs >=2)
                    totcnt += cnt;
            }
        }
        cout<<total<<" "<<totcnt<<endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <iomanip>
#include <cmath> 
#include <map> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAX 10000000
vector<int> adjList[MAX];
int cnt_frnd;
map<int,int> m;

void DFS(int v)
{
    m[v] = 1;
    cnt_frnd++;
    int size = adjList[v].size() , adj;
    for(int i=0;i<size;i++)
    {
        adj = adjList[v][i];
        if(!(m[adj]))
        {
            DFS(adj);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    int t,n,M,u,v,groups;
    //cin>>t;
    t = 1;
    while(t--)
    {
        cnt_frnd=0;
        scanf("%d %d",&n,&M);
        m.clear();

        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&u,&v);
            //2-way relationship
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            m[u] = 0;
            m[v] = 0;
        }

        groups = 0;
        map<int,int>::iterator it;
        for(it = m.begin();it != m.end();it++)
        {
            if(!(it->second))
            {
                groups++;
                DFS(it->first);
            }
        }
        //RESET
        for(it = m.begin();it != m.end();it++)
            adjList[it->first].clear();

        int alone_child = (n - m.size());
        printf("%d\n",alone_child + groups);
    }
    return 0;
}



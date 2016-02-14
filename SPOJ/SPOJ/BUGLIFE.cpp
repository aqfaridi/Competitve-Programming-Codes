#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 2010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<int> adjList[MAX];
vector<int> color(MAX);
// initial color = -1
// first color = 1;
// second color = 0;
bool isBipartite(int s)
{
    queue<int> q;
    int v,u,size;
    color[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            v = adjList[u][i]; //adjacent
            if(color[v] == -1) //not colored
            {
                color[v] = 1 - color[u]; //alternate color
                q.push(v);
            }
            //already colored
            else if(color[v] == color[u]) // same colored adjacent
                return false;
        }
    }
    return true;
}
int main()
{
    int t,n,m,u,v,cases=0;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d %d",&n,&m);
        //initialize
        for(int i=0;i<=n;i++)
        {
            adjList[i].clear();
            color[i] = -1;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        /**
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<adjList[i].size();j++)
                cout<<adjList[i][j]<<" ";
            cout<<endl;
        }
        **/
            
        for(int i=1;i<=n;i++)
        {
          if(color[i] == -1)//not colored (disconnected graph)
          {
              b = isBipartite(i);
              if(b==false)
              {
                printf("Scenario #%d:\nSuspicious bugs found!\n",cases); 
        
                break;
              }
          }
        }
        if(b)
            printf("Scenario #%d:\nNo suspicious bugs found!\n",cases); 
                
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 10010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<int> adjList[MAX];
int main()
{
    int n,m,u,v,k;

    deque<int> q;
   
    scanf("%d %d",&n,&m);
    vector<int> topo_variant(n+1);
    vector<int> indegree(n+1,0);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&v);
            u = i;
            adjList[u].push_back(v);
            //u -> v
            //this means indegree of v increases by 1
            indegree[v] += 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
       // cout<<indegree[i]<<" ";
        if(indegree[i]==0)
            q.push_back(i);
    }
    //cout<<endl;
   // sort(q.begin(),q.end());
   // for(int i=0;i<q.size();i++)
     //   cout<<q[i]<<" ";
    //cout<<endl;
    int parent = 0; 
    while(!q.empty())
    {
        v = q.front();
        q.pop_front();
        topo_variant[v] = parent; //initially v is the main boss
        for(int i=0;i<adjList[v].size();i++)
        {
            indegree[adjList[v][i]] -= 1;
           // for(int x=0;x<n;x++)
             //   cout<<indegree[x]<<" ";
           // cout<<endl;
            if(indegree[adjList[v][i]] == 0)
                q.push_back(adjList[v][i]);
            
            //sort(q.begin(),q.end());
            //for(int i=0;i<q.size();i++)
              //  cout<<q[i]<<" ";
            //cout<<endl;
        }
        parent = v;
    }

    for(int i=1;i<=n;i++)
        cout<<topo_variant[i]<<"\n";
    
    


    return 0;

}


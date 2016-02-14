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
    int n,m,u,v;
    vector<int> indegree(n,0);
    deque<int> q;
    vector<int> topo;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        u -= 1; v -= 1;
        adjList[u].push_back(v);
        //u -> v
        //this means indegree of v increases by 1
        indegree[v] += 1;
    }
    for(int i=0;i<n;i++)
    {
       // cout<<indegree[i]<<" ";
        if(indegree[i]==0)
            q.push_back(i);
    }
    //cout<<endl;
    sort(q.begin(),q.end());
   // for(int i=0;i<q.size();i++)
     //   cout<<q[i]<<" ";
    //cout<<endl;
    int count = 0; 
    while(!q.empty() && count < n)
    {
        v = q.front();
        q.pop_front();
        topo.push_back(v);
        ++count;
        for(int i=0;i<adjList[v].size();i++)
        {
            indegree[adjList[v][i]] -= 1;
           // for(int x=0;x<n;x++)
             //   cout<<indegree[x]<<" ";
           // cout<<endl;
            if(indegree[adjList[v][i]] == 0)
                q.push_back(adjList[v][i]);
            
            sort(q.begin(),q.end());
            //for(int i=0;i<q.size();i++)
              //  cout<<q[i]<<" ";
            //cout<<endl;
        }
    }
    if(count<n)
    {
        printf("Sandro fails.\n");
    }
    else
    {
        for(int i=0;i<topo.size();i++)
            cout<<topo[i]+1<<" ";
        cout<<endl;
    }


    return 0;

}


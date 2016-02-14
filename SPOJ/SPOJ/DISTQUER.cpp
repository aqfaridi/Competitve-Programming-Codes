#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 100010
using namespace std;
struct str
{
    int conn,cost;   
    str(int arg_conn,int arg_cost)
         : conn(arg_conn),cost(arg_cost) {}
};
int visited[MAX];
vector<str> adjList[MAX];

long long DFS(int src,int dest,long long sum)
{
    visited[src]=1;
    if(src==dest)
        return sum;
    //cout<<"src="<<src<<" ";
    //long long  costsum=0;
    for(int i=0;i<adjList[src].size();i++)
    {
        int w=(adjList[src][i]).conn;
        sum += adjList[src][i].cost;
        //cout<<"w="<<w<<"sum="<<sum<<endl;
        //if(w==dest)
         //   return sum;
        
        if(!visited[w])
            DFS(w,dest,sum);
    }
}
int main()
{
     int q,n,a,b,cost,source,dest;
     //vector<str> adjList[100010];
     //int visited[MAX];
     scanf("%d",&n);
     for(int i=0;i<n-1;i++)
     {
         scanf("%d %d %d",&a,&b,&cost);
         adjList[a].push_back(str(b,cost));
         adjList[b].push_back(str(a,cost));
     }
     /*
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<adjList[i].size();j++)
         {        
            cout<<adjList[i][j].conn<<" "<<adjList[i][j].cost<<endl;
         }
     }
     */
     scanf("%d",&q);
     //cout<<q<<endl;
     for(int i=0;i<q;i++)
     {
        memset(visited,0,sizeof(visited));
        scanf("%d %d",&source,&dest);
        //cout<<source<<" "<<dest<<endl;
        cout<<DFS(source,dest,0)<<endl;
     }
            
    return 0;
}

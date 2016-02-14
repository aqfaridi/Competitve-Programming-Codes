#include<iostream>
#include<cstdio>
#include<vector>
#define SIZE 3001
#define MIN(a,b) (a>b?b:a)

using namespace std;
int n,count,x,articulation[SIZE],arrival[SIZE],low[SIZE],visited[SIZE],source,rcount;

void connect(vector< vector<int> > &adj,int node)
{
    visited[node]=1;
    arrival[node]=++x;
    int depth;
    depth=x;
    low[node]=x;
    int i,j,size,w;
    size=adj[node].size();
    for(i=0;i<size;i++)
    {
        w=adj[node][i];
        if(visited[w]==1)
        {
            depth=MIN(depth,arrival[w]);
        }
        else
        {
            if(node==source)
                rcount++;

            connect(adj,w);

            if(low[w]>=arrival[node] && node!=source && articulation[node]==-1)
            {
                count++;
                articulation[node]=1;
            }
            low[node]=MIN(low[node],low[w]);
        }
    }
    low[node]=MIN(low[node],depth);
    return;

}

int main()
{
    int i,t,m,k,a,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        vector< vector<int> > adj(n);

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&y);
            adj[a].push_back(y);
            adj[y].push_back(a);
        }
        count=0;
        x=0;
        source=0;
        rcount=0;
        for(i=0;i<n;i++)
        {
            articulation[i]=arrival[i]=low[i]=-1;
            visited[i]=0;
        }
        connect(adj,0);
        if(rcount>1)
            count++;
        count = count * k;
        printf("%d\n",count);
    }
    return 0;
} 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <list>
#define MAX 3010
using namespace std;
int graph[MAX][MAX],discover[MAX],size[MAX],low[MAX],pred[MAX],visited[MAX];
list<int> ap;
int timee;
void DFS_LOW(int v)
{
    visited[v]=1;
    discover[v]=++timee;
    low[v]=discover[v];

    for(int i=0;i<size[v];i++)
    {
        int w=graph[v][i];
        if(!visited[w])
        {
            pred[w]=v;
            DFS_LOW(w);
            if(discover[v]==1)//root
            {
                if(size[v]>=2 && low[w] > discover[v])
                    ap.push_front(v);

            }
            else if (low[w] >= discover[v])
                ap.push_front(v);

            low[v]=min(low[v],low[w]);
        }
        else if(pred[v]!=w)
        {
            low[v]=min(low[v],discover[w]);
        }
    }
}

int main()
{
    int t,edge,vertices;
    long long cost;
    int vertex1,vertex2;
    scanf("%d",&t);
    while(t--)
    {
        ap.clear();
        timee=0;
        memset(visited,0,sizeof(visited));
        memset(low,0,sizeof(visited));
        memset(pred,0,sizeof(pred));
        memset(graph,0,MAX*MAX*sizeof(graph[0][0]));
        memset(discover,0,sizeof(discover));
        memset(size,0,sizeof(size));
        scanf("%d %d %lld",&vertices,&edge,&cost);
        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&vertex1,&vertex2);
            assert(vertex1>=0 && vertex1<vertices);
            assert(vertex2>=0 && vertex2<vertices);
            graph[vertex1][size[vertex1]++] = vertex2;
            graph[vertex2][size[vertex2]++] = vertex1;
        }
    
        for(int i=0;i<vertices;i++)
        {
           
                if(!visited[i])
                    DFS_LOW(i);
        }
        ap.sort();
        ap.unique();
        /*
        list<int>::iterator it;
        for(it=ap.begin();it!=ap.end();it++)
            cout<<*it<<" ";
          */  

        printf("%lld\n",cost*ap.size());

    }
    return 0;
}

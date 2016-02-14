#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
#define MOD 1000000007
using namespace std;
int parent[MAX];
void makeset(int n)
{
    for(int i=1;i<=n;i++)      
        parent[i]=-1;
    
}
int find(int x)
{
    if(parent[x] < 0)
        return x;
    else
        return find(parent[x]);
}
void uunion(int x,int y)
{
    int xRoot=find(x);
    int yRoot=find(y);

    if(xRoot != yRoot)
    {
        if(parent[xRoot] >= rank[yRoot])
        {
            parent[yRoot]=xRoot;
            rank[xRoot] += rank[yRoot];
            rank[yRoot]=0;
        }
        else
        {
            parent[yRoot]=xRoot;
            rank[yRoot] += rank[xRoot];
            rank[xRoot]=0;
        }
    }
}
int main()
{
    int t,n,m,count,x,y;
    long long now;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d%d",&n,&m);
        makeset(n);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            uunion(x,y);
        }

        now=1;
        for(int i=1;i<=n;i++)
        {
            if(rank[i] > 0)
            {
                count++;
                now = (now * (rank[i]) )%MOD ;
            }
        }
        printf("%d %lld\n",count,now);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 10010
using namespace std;
int adj[MAX][MAX];
int queue[MAX],front = -1 ,rear = -1;

void insert_queue(int vertex)
{
    if(rear == MAX-1)
        cout<<"overflow"<<endl;
    else
    {
        if(front == -1) // queue is initially empty
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int del_item;
    if(front == -1 || front > rear)
        cout<<"underflow"<<endl;
    else
    {
        del_item = queue[front];
        front = front + 1;
        return del_item;
    }
}
int indegree(int v,int n)
{
    int i,in_deg = 0;
    for(int i=0;i<n;i++)
    {
        if(adj[i][v] == 1) // indegree of v
            in_deg++;

    }
    return in_deg;
}
int main()
{
    int n,x,y,m;
    int v,count,topo_order[MAX],indeg[MAX];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        x -= 1; y-=1;
        adj[x][y] = 1;
    }
    for(int i=0;i<n;i++)
    {
        indeg[i] = indegree(i,n);
        cout<<indeg[i]<<" ";
        if(indeg[i] == 0)
            insert_queue(i);
    }
    count = 0;
    for(int i=0;i<n;i++)
        cout<<queue[i]<<" ";
    
    cout<<endl;
    while(!isEmpty_queue() && count < n)
    {
        v = delete_queue();
        cout<<v<<" ";
        topo_order[++count] = v; // add vertex v to topo_order array
        //delete all edges going from vertex v
        for(int i=0;i<n;i++)
        {
            if(adj[v][i] == 1) //out degree
            {
                adj[v][i] = 0;
                indeg[i] = indeg[i] - 1;
                if(indeg[i]==0)
                    insert_queue(i);
            }
        }
    }
    if(count<n)
    {
        printf("\n");
    }
    else
    {
        for(int i=1;i<=count;i++)
            printf("%d ",topo_order[i]);
        printf("\n");
    }
    return 0;
}


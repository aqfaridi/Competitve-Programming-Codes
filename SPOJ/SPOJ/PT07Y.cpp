#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#define MAX 10010
using namespace std;
int visited [2*MAX];
vector<int> adjList[MAX];//array of vectors
void DFS(int v)
{
    visited[v] = 1;
    for(int w=0;w<adjList[v].size();w++)
    {
        //adjList[v][w] is the adjacent node
        if(!visited[adjList[v][w]])
            DFS(adjList[v][w]);
    }
}
int main()
{
    //max edges in undirected graph MAX*(MAX-1)
    //so maintaining adjList for storing all relations(edges)
    int t=1,edges,u,v,vertices;

    while(t--)
    {
        memset(visited,0,sizeof(visited));
        scanf("%d %d",&vertices,&edges);        
        for(int i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            u -= 1; v -= 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        /**
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<size[i];j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }
        **/
        if(edges > vertices - 1)
        {
            cout<<"NO"<<endl; // since it is graph
        }
        else
        {
            // depth first search call
            DFS(0);
            int node;
            for(node=0;node<vertices;node++)
                if(visited[node] != 1)
                    break;
             
            if(node == vertices)
                cout<<"YES"<<endl;  
            else
                cout<<"NO"<<endl;
        }
    }   
    return 0;
}


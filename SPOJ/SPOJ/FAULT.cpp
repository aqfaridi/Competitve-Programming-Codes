#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1001
#define MAX1 201
using namespace std;
vector<int> adjList[MAX];
vector<int> chunkList[MAX1];
int ser[MAX];
int main()
{
    int chunk,server,var,var2;
    scanf("%d %d",&chunk,&server);
    for(int i=0;i<server;i++)
    {
        scanf("%d",&var);
        for(int j=0;j<var;j++)
        {
            scanf("%d",&var2);
            adjList[i].push_back(var2);
            chunkList[var2].push_back(i);
        }

    }
    /*for(int i=0;i<server;i++)
    {
        for(int j=0;j<server;j++)
        {
            
        }
    }
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<chunkList[i].size();j++)
            cout<<chunkList[i][j]<<" ";
        cout<<endl;
    }
    */
    int temp;
    for(int i=0;i<chunk;i++)
    {
        for(int j=0;j<chunkList[i].size();j++)
        {
            //ser[chunkList[i][j]] +=1;
            //server[temp] += 1;
            for(int k=0;k<server;k++)
            {
                for(int m=0;m<adjList[chunkList[i][j]].size();m++)
                {
                     += adjList[chunkList[i][j]][m]
                }
            }
        }
       
    }

    int max=ser[0];
    int pos=0;
    for(int i=0;i<MAX;i++)
    {
        if(ser[i]>max)
        {max=ser[i];
            pos=i;}
    }
    cout<<"1"<<endl;
    cout<<pos<<endl;

    return 0;
}

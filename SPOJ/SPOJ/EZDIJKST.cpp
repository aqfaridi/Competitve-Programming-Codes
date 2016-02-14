#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <algorithm>
#define MAX 10010
#define MOD 1000000007
#define NIL -1
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<pair<int,int> > adjList[MAX];
vector<int> status(MAX);
vector<int> pathLength(MAX);
int n;
int min_temp()
{
    int minn = INT_MAX,k=NIL;
    for(int i=0;i<n;i++)
        if(status[i] == false && pathLength[i] < minn)
        {
            minn = pathLength[i];
            k = i;
        }

    return k;
}
void Dijkstra(int s)
{
    int current;
    pathLength[s] = 0;
    while(1)
    {
        current = min_temp();
        //cout<<current<<endl;
        if(current == NIL)//NIL return only when all vertex are visited or remaining vertex are all infinite
            return;  //function returned

        status[current] = true;//PERM
        //adjacent nodes relabelling
        for(int i=0;i<adjList[current].size();i++)
        {
            pair<int,int> adj = adjList[current][i];
            if(!status[adj.first])
                if(pathLength[current] + adj.second < pathLength[adj.first])
                    pathLength[adj.first] = pathLength[current] + adj.second ;
        }
        //for(int i=0;i<n;i++)
          //  cout<<pathLength[i]<<" ";
        //cout<<endl;
        
    }
}
int main()
{
    int t,m,u,v,a,b,cost;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<MAX;i++)
            adjList[i].clear();

        scanf("%d %d",&n,&m);

        status.assign(n,false); // temp=false and perm=true
        pathLength.assign(n,INT_MAX);//initially, infinite

        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            //directed graph
            u -= 1 ; v-=1;
            adjList[u].push_back(make_pair(v,cost));
        }
        scanf("%d %d",&a,&b);//source and destination

        Dijkstra(a-1);
        
        //for(int i=0;i<n;i++)
          //  cout<<pathLength[i]<<" ";
        if(pathLength[b-1] != INT_MAX)
            cout<<pathLength[b-1]<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}


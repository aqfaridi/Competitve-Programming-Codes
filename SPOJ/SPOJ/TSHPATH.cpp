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
typedef pair<int,int> pii;

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
void dijkstra(int s,int d)
{
    //PQ + BFS
    priority_queue< pii,vector< pii >,greater< pii > > q;
    q.push(pii(0,s)); // wt then vertex
    pathLength[s] = 0; 
    int u,v,w,size;
    while(!q.empty())
    {
        u = q.top().second; //vertex
        q.pop();
        if(status[u]) continue; //already visited
        if(u == d) break;
        size = adjList[u].size();
        for(int i=0;i<size;i++)
        {
            v = adjList[u][i].second; //adjacent
            w = adjList[u][i].first;
            if(!status[v] && pathLength[v] > pathLength[u] + w)
            {
                pathLength[v] = pathLength[u] + w;
                q.push(pii(pathLength[v],v));
            }
        }
        status[u] = true;
   }
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
struct mp
{
    char ch[20];
    int num;
};
int main()
{
    int t,m,u,v,a,b,cost,r;
    string str,str1,str2;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<MAX;i++)
            adjList[i].clear();

        scanf("%d",&n);
        map<string,int> my;       

        status.assign(n,false); // temp=false and perm=true
        pathLength.assign(n+1,INT_MAX);//initially, infinite

        for(int i=1;i<=n;i++)
        {
            cin>>str;
            my[str] = i;
            scanf("%d",&m);//neighbour
            for(int j=0;j<m;j++)
            {
                scanf("%d %d",&v,&cost);
                //directed graph
                u = i;
                //u -= 1 ; v-=1;
                adjList[u].push_back(make_pair(cost,v));//greater<functional>
            }
        }
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            status.assign(n+1,false);
            pathLength.assign(n+1,INT_MAX);

            cin>>str1>>str2;
            a = my[str1];
            b = my[str2];//source and destination
            //cout<<a<<b<<endl;
            dijkstra(a,b);
        
            //for(int i=0;i<=n;i++)
              //cout<<pathLength[i]<<" ";
            if(pathLength[b] != INT_MAX)
                cout<<pathLength[b]<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}


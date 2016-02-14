#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 10010
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<double,int> pii;
vector< pii > adjList[MAX];
vector<double> prob(MAX);
vector<bool> status(MAX);
int N;

void dijkstra(int s,int d)
{
    prob.assign(N+1,0.0);
    status.assign(N+1,false);
    priority_queue< pii , vector< pii > , less< pii > > q;
    q.push(pii(1.0,s));
    prob[s] = 1.0;
    int u,v,size;
    double w;
    while(!q.empty())
    {
        u = q.top().second; // vertex
        q.pop();
        if(status[u]) continue; //already visited
        if(u == d) break;
        size = adjList[u].size();
        for(int i=0 ; i<size ; i++)
        {
            v = adjList[u][i].second;
            w = adjList[u][i].first;
            if(!status[v] && prob[v] < prob[u] * w * 1.0)
            {
                prob[v] = prob[u] * w * 1.0;
                q.push(pii(prob[v],v));
            }
        }
        status[u] = true;
    }

}
int main()
{
    int u,v,M;
    int cost;
    while(1)
    {

        scanf("%d",&N);
        if(N==0) break;
        for(int i=0;i<=N;i++)
            adjList[i].clear();

        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            //undirected
            //printf("%.2f\n",cost*1.0/100);
            adjList[u].pb(pii((1.0*cost)/100,v));
            adjList[v].pb(pii((1.0*cost)/100,u));

        }
        dijkstra(1,N);
        /**
        for(int i=0;i<=N;i++)
            cout<<prob[i]<<" ";
        cout<<endl;
        **/
        printf("%.6lf percent\n",prob[N]*100.0 + 1e-10);
            
    
    }
    return 0;
}


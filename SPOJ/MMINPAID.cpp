#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#include <cassert>
#define MAX 100010
#define MOD 1000000007
int p[20],r[20],a[20],b[20],c[20],n,m;
int mem[(1<<12)][20];
int solve(int mask,int prev)
{
    if(prev == n-1) {return 0;}
    
    assert(mask>=0);assert(prev>=0);
    int&res = mem[mask][prev];
    if(res != 522133279)    return res;

    for(int i=0;i<m;i++)
    {
        assert(i>=0);assert(i<10);
        if(a[i] == prev)
        {
            //if(mask & (1<<b[i]))    continue;
            if(mask & (1<<c[i]))
                res = min(res,p[i]+solve(mask|(1<<b[i]),b[i]));
            else
                res = min(res,r[i]+solve(mask|(1<<b[i]),b[i]));
        }
    }
    return res;
}
/*
typedef pair<int,pair<int,int> > tri;
int d[110][(1<<12)],mask;
void dijikstra(int src,int dst)
{
    priority_queue< tri , vector< tri > , greater< tri > > q;
    q.push( make_pair(0,make_pair(src,1)));
    int u,v,w,size;
    d[src][1] = 0;
    mask = 1;
    while(!q.empty())
    {
        u = q.top().second.first;
        mask = q.top().second.second;
        q.pop();
        if(u == dst)    break;

        for(int i=0;i<m;i++)
        {
            if(a[i] == u)
            {
                v = b[i];
                if(mask & (1<<c[i]))
                    w = p[i];
                else
                    w = r[i];
              
                trace3(u,v,w);
                trace1(mask);
                trace2(d[v][mask],(d[u][mask]+w));
                if(d[v][mask|(1<<b[i])] >= d[u][mask|(1<<b[i])]+w)
                {
                    d[v][mask|(1<<b[i])] = d[u][mask|(1<<b[i])] + w;
                    q.push(make_pair(d[v][mask|(1<<b[i])],make_pair(v,(mask | (1<<b[i])))));
                    trace3(d[v][mask],v,(mask|(1<<b[i])));
                }
            }
        }
        cout<<"---------------"<<endl;
        

    }
}
*/
int main()
{
    ios::sync_with_stdio(false);
    int route_cost=0;
    memset(mem,31,sizeof mem);
    //memset(d,31,sizeof(d));
    cin>>n>>m;
    assert(n<=10);
    assert(m<=10);
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>p[i]>>r[i];
        a[i] -= 1;b[i] -= 1;c[i] -= 1;
    }

    route_cost = solve(1,0);
    /*
    dijikstra(0,n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
    */
    if(route_cost != 522133279)
        cout<<route_cost<<endl;
    else
        cout<<"impossible"<<endl;
    return 0; 
}

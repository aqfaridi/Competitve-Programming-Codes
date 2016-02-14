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

#define MAX 100010
#define MOD 1000000007
#include <cassert>

int src[16],dst[16],n,m,h,q,k,b;
int mem[(1<<12)][110];
int d[110][110];
void warshall()
{
    for(int k=0;k<n;k++) 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}

int solve(int mask,int prev)
{
    if(mask == ((1<<k)-1))  return d[prev][h];

    int& res = mem[mask][prev];
    if(res != 522133279)   return res;
    
    for(int i=0;i<k;i++) 
    {
        if(mask & (1<<i))   continue;      //already visited task 
        //transition: prev -> src[i]
        //trace3(d[prev][src[i]],d[src[i]][dst[i]],(mask|(1<<i)));
        res = min(res,d[prev][src[i]] + d[src[i]][dst[i]] + solve((mask | (1<<i)),dst[i]));
    }
    assert(res >= 0);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t,x,y,c;
    cin>>t;
    while(t--)
    {
        memset(mem,31,sizeof mem);
        memset(d,31,sizeof d);
        cin>>n>>m>>h;
        h -= 1;
        for(int i=0;i<n;i++)
            d[i][i] = 0;

        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>c;
            x-=1;y-=1;
            d[x][y] = c;
            d[y][x] = c;
        }
        warshall();
        cin>>q;
        k = 0;
        for(int i=0;i<q;i++)
        {
            cin>>x>>y>>b;
            x-=1;y-=1;
            while(b--)
                src[k] = x,dst[k++] = y;
        }
        cout<<solve(0,h)<<endl;
    }
    return 0; 
}

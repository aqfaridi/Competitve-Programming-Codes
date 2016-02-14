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
#include <climits>
#include <cassert>

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
int x[110],y[110],n,epsilon,k;
double dist[110],p[110],mem[110][110];

double solve(int idx,int k)
{
    if(k == 0)  return 1;
    if(idx == n)    return 0;

    double& res = mem[idx][k];
    if(res != -1)   return res;

    res = p[idx] * solve(idx+1,k-1);
    res += (1-p[idx]) * solve(idx+1,k);

    return res;
}

bool binary(double r)
{
    rep(i,n)    
    {
        if(dist[i] <= r)
            p[i] = 1;
        else
            p[i] = exp(1 - dist[i]*dist[i]/(r*r));
    }

    rep(i,n+1) rep(j,k+1) mem[i][j] = -1;
    double res = solve(0,k);

    return ( (1-res)*1000 <= epsilon );     
}
int main()
{
    ios::sync_with_stdio(false);
    int x0,y0;
    cin>>n>>k>>epsilon;
    cin>>x0>>y0;
    rep(i,n)    cin>>x[i]>>y[i];
    rep(i,n)    dist[i] = hypot(x[i]-x0,y[i]-y0);
    
    double mid,low = 0,high = 1000000;
    while( abs(low-high) > 1e-9)
    {
        mid = (low + high)/2;
        if(binary(mid))
            high = mid;
        else
            low = mid;
    }

    printf("%.15lf\n",(low+high)/2);

    return 0; 
}

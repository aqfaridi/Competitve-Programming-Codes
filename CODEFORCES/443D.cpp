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
double p[500];
double mem[500][500];
int limit,n;
double solve(int idx,int cnt)
{
    if(cnt == limit)    return 1.0;
    if(idx == n)    return 0.0;
    
    double& res = mem[idx][cnt];
    if(res != -1.0)  return res;
    res = 0.0;
    double t1=0.0,t2=0.0;
    
    t1 = p[idx]*solve(idx+1,cnt+1) + (1.0 - p[idx])*solve(idx+1,cnt);
    t2 = solve(idx+1,cnt);
    trace2(t1,t2);
    res = max(t1,t2);
    trace1(res);
    return res;
}
int main()
{
    double maxx = -10.0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            mem[i][j] = -1.0;

    for(int i=1;i<=n;i++)    
    {
        limit = i;

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                mem[i][j] = -1.0;
        maxx = max(maxx,solve(0,0));
        trace1(maxx);
    }

    printf("%.9lf\n",maxx);
    return 0; 
}

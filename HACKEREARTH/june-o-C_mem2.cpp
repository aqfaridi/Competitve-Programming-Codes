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
double p[20];
int val[20];
double mem[20][(1<<17)];
int k,n;
double solve(int cnt,int profile,int money)
{
    if(cnt == 0)
        return 1.0;

    double& res = mem[cnt][profile];
    if(res != -1.0)   return res;
    res = 0;

    for(int i=0;i<n;i++)
        if(money-val[i] >= 0 && !(profile & (1<<i)))
        {
            double t = p[i]*solve(cnt-1,(profile | (1<<i)),money-val[i]) + (1.0 - p[i])*solve(cnt,(profile | (1<<i)),money-val[i]); 
            res = max(res,t);
        }
    
    return res;
}
int main()
{
    int t,price,v,var;
    double ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>price;
        for(int i=0;i<n;i++)
        {
            cin>>v>>var;
            val[i] = v;
            p[i] = var/100.0;
        }

        for(int i=0;i<=k;i++)
                for(int j=0;j<=(1<<n);j++)
                    mem[i][j] = -1.0;
    
        ans = solve(k,0,price);
        printf("%.6lf\n",ans);    
    }
    return 0; 
}

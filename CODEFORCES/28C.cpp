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
double mem[65][65][65][2];
LL C[65][65];
int basins[65];
LL nCr(int n,int r)
{

    if(r == 0)  return 1;
    if(n == r)  return 1;      

    LL& res = C[n][r];
    if(res != -1)   return res;
    
    res = nCr(n-1,r-1) + nCr(n-1,r);
    
    return res;
}

double expo(double a,int n)
{
    double result = 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}

double bernoulli(int n,int i,double ps)
{
    return (nCr(n,i) * expo(ps,i) * expo(1.0 - ps,n-i));
}

//n = unprocessed students
//m = unprocessed rooms
//mx = max. queue length
//eq = to keep track in path whether max. queue length reach is mx possbile
double solve(int n,int m,int mx,int eq)
{
    if(m <= 0)   return (eq ? 1:0);

    double& res = mem[n][m][mx][eq];
    if(res != -1)    return res;
    res = 0;


    for(int i=0;i<=min(n,basins[m]*mx);i++) //student who goes to m-th room
        res += bernoulli(n,i,(1.0/m)) * solve(n-i,m-1,mx,eq || (i > basins[m]*(mx-1)) ); //if i students > basins[m]*(mx-1) then max. queue length is mx possible in path followed in brute force
    
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)    cin>>basins[i]; //basins in i-th room

    rep(i,60+1)  rep(j,60+1) C[i][j] = -1;
    rep(i,60+1)  rep(j,60+1) rep(k,60+1) rep(l,2) mem[i][j][k][l] = -1;

    //find expection of max queue length
    //iterate over all queue length possible (i) and multiply with prob.
    //that max. queue length = i
    double ans = 0;
    for(int i=0;i<=n;i++)
        ans += i*solve(n,m,i,0);
    
    printf("%.15lf\n",ans);
    return 0; 
}

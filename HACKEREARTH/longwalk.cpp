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
int n,u,v;
LL k;
LL a[60][60],result[60][60];
void multiply(LL a[][60],LL b[][60])
{
    LL c[60][60] = {0};
    rep(i,n)    rep(j,n) {
        c[i][j] = 0;    
        rep(k,n)    c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
    }
    rep(i,n) rep(j,n)   a[i][j] = c[i][j];
}
void expo(LL a[][60],LL k)
{
    while(k)
    {
        if((k&1))
            multiply(result,a);
        multiply(a,a);
        k >>= 1;
    }

    rep(i,n)    rep(j,n) a[i][j] = result[i][j];
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>u>>v;
        rep(i,n)    rep(j,n)  {  cin>>a[i][j]; result[i][j] = a[i][j]; }
        k -= 1;
        expo(a,k);
        //rep(i,n){    rep(j,n) cout<<a[i][j]<<" "; cout<<endl; } 
        cout<<a[u][v]<<endl;
    }
    return 0; 
}

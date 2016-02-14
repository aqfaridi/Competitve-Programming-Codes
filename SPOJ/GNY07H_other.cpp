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
int f[60],g[60],h[60];
void precalc()
{
    f[1] = g[1] = h[1] = 1;
    f[0] = 1; g[0] = h[0] = 0;
    for(int i=2;i<=60;i++)
    {
        f[i] = f[i-1] + f[i-2] + 2*h[i-1] + g[i-1];
        h[i] = f[i-1] + h[i-1];
        g[i] = f[i-1] + g[i-2];
    }
}
int main()
{
    precalc();
    ios::sync_with_stdio(false);
    int t,n,cases=0;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>n;
        cout<<cases<<" "<<f[n]<<endl;
    }
    return 0; 
}

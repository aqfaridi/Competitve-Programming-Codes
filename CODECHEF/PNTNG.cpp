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
typedef pair< LL,LL > pll;

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
vector< pll > v;
int main()
{
    ios::sync_with_stdio(false);
    LL n,m,h,tk,ck,minn;
    LL sum,reach,cost;
    cin>>n>>m>>h;
    for(int i=0;i<h;i++)
    {
        cin>>tk>>ck;
        v.pb(mp(ck,tk));
    }
    
    reach = n*m;
    cost = 0;

    sort(v.begin(),v.end());
    int size = v.size();
    for(int i=0;i<size;i++)
    {
        minn = min(v[i].second,reach);
        cost += minn * v[i].first;
        reach -= minn;
        //trace3(v[i].first,v[i].second,reach);
    }
    if(reach == 0)
        cout<<cost<<endl;
    else
        cout<<"Impossible"<<endl;
    
    return 0; 
}

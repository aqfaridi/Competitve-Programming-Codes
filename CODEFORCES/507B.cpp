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

int main()
{
    ios::sync_with_stdio(false);
    double r,x,y,dx,dy;
    cin>>r>>x>>y>>dx>>dy;
    if(x == dx && y == dy){
        cout<<0<<endl;
        return 0;
    }
    if(x == dx){
        double shift = 2*r;
        int ans = ceil(abs(dy-y)/shift);
        cout<<ans<<endl;
        return 0;
    }
    if(y == dy){
        double shift = 2*r;
        int ans = ceil(abs(dx-x)/shift);
        cout<<ans<<endl;
        return 0;
    }
    double arg = abs((1.0*(dy-y))/(dx-x));
    double theta = atan(arg);
    double shift = 2*r*cos(theta);
    int ans = ceil(abs(dx-x)/shift);
    cout<<ans<<endl;
    return 0; 
}

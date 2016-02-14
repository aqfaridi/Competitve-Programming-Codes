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

#define MAX 131078 
#define MOD 1000000007

int m[MAX];
int pos[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        rep(i,n)cin>>m[i];
        rep(i,k)cin>>pos[i];
        sort(m,m+n);sort(pos,pos+k);
        int  maxx = INT_MIN ;
        rep(i,n){
            //cout<<m[i]<<" "<<pos[i]<<endl;
            maxx = max(maxx , (int)abs(m[i]-pos[i]));
        }
        cout<<maxx<<endl;
    }
    return 0; 
}

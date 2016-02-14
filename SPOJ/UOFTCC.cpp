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
vector<LL> v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,c,test,cnt,maxx;
    cin>>test;
    while(test--)
    {
        cin>>n>>c>>t;
        v.resize(n);
        rep(i,n)
            cin>>v[i];
        maxx = v[0];
        sort(all(v));
        v.pb(LONG_MAX);
        v.pb(LONG_MAX);
        n += 2;
        cnt = 0;
        for(int i=1;i<n-1;i++)
        {
            if(v[i] - v[i-1] > c)   break;
            if((v[i] - v[i-1] <= c) && (v[i+1] - v[i-1] > c) && (v[i] > maxx)) 
            {
                maxx = v[i];
                cnt++;
            }
        }
        cout<<maxx<<" "<<cnt*t<<endl;
            
    }
    return 0; 
}

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
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 100010
#define MOD 1000000007
int arr[MAX];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,G,x,y,maxx,size,cnt;
    t = 1;
    while(t--)
    {
        cin>>n>>m;
        rep(i,n)
            cin>>arr[i];
        rep(k,m)
        {
            cin>>G>>x>>y;
            x-=1;y-=1;
            for(int i=x;i<=y;i++)
                if(__gcd(G,arr[i]) > 1)
                    v.pb(arr[i]);
            size = v.sz;
            if(size)
            {
                cnt = 0;
                maxx = *max_element(all(v));
                for(int j=0;j<size;j++)
                    if(v[j] == maxx)
                        cnt++;
                cout<<maxx<<" "<<cnt<<endl;
            }
            else
                cout<<-1<<" "<<-1<<endl;
            v.clear();
        }
    }
    return 0; 
}

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

#define MAX 10010
#define MOD 1000000007
LL arr[MAX],cumm[MAX];
vector<LL> v[61];
void precompute()
{
    LL pwr;
    for(int j=1;j<=1000010;j++)
    {
        pwr = j;
        for(int i=1;i<=60;i++)
        {
            
            v[i].pb(pwr);
            if(pwr > (1LL<<60)/j) 
                break;
            pwr *= j;                
        }
    }        
}
int main()
{
    precompute();
    //for(int i=1;i<=60;i++)
    //	cout<<v[i].size()<<endl;

    ios::sync_with_stdio(false);
    int t,n,q,size;
    LL x,ans,root; 
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        
	    cumm[n] = (arr[n]+MOD)%MOD;
        for(int i=n-1;i>=1;i--)
            cumm[i] = (cumm[i+1] + arr[i] + MOD)%MOD;
        while(q--)
        {
            cin>>x;
            ans = 0;
            int i=1;
            for(;i<=n;i++)
            {
                size = v[i].size();
                if(i == 1)
                    root = x;
                else if(i == 2)
                    root = (LL)sqrt(x);
                else
                    root = upper_bound(v[i].begin(),v[i].end(),x) - v[i].begin();
                //trace3(i,root,x);
                ans = (ans + ((root%MOD)*arr[i])%MOD)%MOD;
                if(root == 1)
                    break;
            }
            if(i < n)
                ans = (ans + cumm[i+1] + MOD)%MOD;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0; 
}

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
vector<int> cut;
int pos[MAX],temp[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n,k,p,var,x1,x2,f1,f2;    
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>pos[i];
        temp[i-1] = pos[i];
    }
    sort(temp,temp+n);
    for(int i=1;i<n;i++)
        if(temp[i] - temp[i-1] > k)
            cut.pb(i);
    
    rep(i,p)
    {
        cin>>f1>>f2;
        x1 = pos[f1]; x2 = pos[f2];
        int idx1 = lower_bound(temp,temp+n,x1) - temp;  
        int idx2 = lower_bound(temp,temp+n,x2) - temp;
        if(idx1 > idx2) swap(idx1,idx2);
        int idx = upper_bound(cut.begin(),cut.end(),idx1) - cut.begin();
        
        if(idx == cut.size())
        {
            cout<<"Yes"<<endl;
            continue;
        }

        int c = cut[idx];
        if( c > idx2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0; 
}

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
int arr[MAX],mark[MAX];
vector< pii > v;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,l,r,q;
    cin>>n>>m;
    v.clear();
    for(int i=0;i<m;i++){
        cin>>l>>r>>q;
        l -= 1; r -= 1;
        v.pb(mp(l,r));
        for(int i=0;i<30;i++)
            if((q & (1<<i))){
                arr[l] |= (1<<i);
                arr[r+1] |= (1<<i);
            }        
    }

    sort(v.begin(),v.end());
    l = v[0].first;
    r = v[0].second;
    bool b = false;
    for(int i=1;i<m;i++){
        if(v[i].first <= r && v[i].second <= r)            
            b = true;
        if(v[i].first <= r) r = max(r,v[i].second);
        else{
            l = v[i].first;
            r = v[i].first;
        }
    }

    if(b){
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<30;j++)
            if((arr[i-1]&(1<<j)))
                arr[i] ^= (1<<j);
    }

    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0; 
}


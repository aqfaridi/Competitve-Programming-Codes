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
typedef pair<LL,LL> pii;
typedef pair<LL,pii > piii;
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

#define MAX 1000010
#define MOD 1000000007
priority_queue<piii> Q;
int mrk[MAX];
LL a[MAX];
LL done[MAX];
int main()
{
    ios::sync_with_stdio(false);
    LL n,nm,nmp,vlp,loss,gain,dif,vl,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nm;
        a[nm]++;
    }
    for(int i=0;i<=MAX;i++){
        if(a[i] > 0){
            loss = (i-1)*a[i-1] + (i+1)*a[i+1];
            Q.push(mp((i*a[i]-loss),mp(i*a[i] , i)));
        }
    }
    
    mrk[0] = 1;
    while(!Q.empty()){
        piii p = Q.top();
        dif = p.first;
        gain = p.second.first;
        nm = p.second.second;        
        Q.pop();
        if(mrk[nm])
            continue;

        bool b= false;

        if(mrk[nm-1] && a[nm-1] > 0)
        {
            dif += (nm-1)*a[nm-1];
            b = true;
        }
        if(mrk[nm+1] && a[nm+1] > 0)
        {
            dif += (nm+1)*a[nm+1];
            b = true;
        }
        if(b and !done[nm]){
             Q.push(mp((dif),mp(gain , nm)));
             done[nm] = 1;
            continue;
        }
        mrk[nm] = 1;
        mrk[nm-1] = 1;
        mrk[nm+1] = 1;
        ans += gain;
    }
    cout<<ans<<endl;
    return 0; 
}

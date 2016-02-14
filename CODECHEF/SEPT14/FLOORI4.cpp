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
LL n,m;
LL psum(LL i){
    LL M = m*30;
    i %= M;
    LL a = (i*(i+1))%M;
    LL b = (a*(2*i+1))%M;
    LL c = (3*i*i)%M;
    LL d = (c + 3*i - 1 + M)%M;
    LL e = (b*d)%M;
    return e/30;
}
LL sum(LL prev,LL idx){
    return (psum(idx)%m-psum(prev)%m+m)%m;
}
LL pwr(LL i)
{
    i %= m;
    return (((i*i)%m*i)%m*i)%m;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL ans,prev,idx;
    cin>>t;
    while(t--)
    {
        cin>>n>>m; 
        prev = sqrt(n);
        ans = 0;
        for(LL i=sqrt(n);i>=1;i--){
            idx = n/i;
            ans = (ans + (pwr(i)*idx)%m + (i*sum(prev,idx))%m)%m;
            prev = idx;
        }
        cout<<ans<<endl;
    }
    return 0; 
}

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
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    LL remain,cnt,d,a,n,k;
    pair<LL,LL> ans = mp(INT_MAX,INT_MAX);
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    for(LL i=1;i<=k+1;i++){
        remain = (k-i);
        for(LL j=max(i+1,n-remain-1);j<=n;j++){
            if((arr[j]-arr[i])%(j-i) != 0)  continue;
            d = (arr[j]-arr[i])/(j-i);
            a = arr[i] - d*(i-1);
            cnt = 0;
            for(int t = 1;t<=n;t++)
                if(arr[t] != a + (t-1)*d) cnt++;
            if(cnt <= k)
                ans = min(ans,mp(a,d));
        }
    }
    rep(i,n)
        cout<<ans.first + ans.second*i<<" ";
    return 0; 
}

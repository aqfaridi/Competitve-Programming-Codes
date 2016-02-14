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

#define MAX 1000010
#define MOD 1000000007
int arr[MAX],cnt[MAX],sieve[MAX],mu[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n,maxx=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
        maxx = max(maxx,arr[i]);
    }

    //factor sieve  : helper for mobius calculation    
    //also helps in checking square free number
    for(int i=2;i<=maxx;i++)
        if(!sieve[i])
            for(int j=i;j<=maxx;j+=i)
                if(!sieve[j])
                    sieve[j] = i;

    LL ans = 0;
    for(int i=1;i<=maxx;i++)
    {
        //mobius fn itself property of IRP(inclusion-exclusion principle)
        //mobius calc = mu[i]
        if(i == 1) mu[i] = 1;
        else if(sieve[i/sieve[i]] == sieve[i]) mu[i] = 0;
        else
            mu[i] = -1 * mu[i/sieve[i]];

        if(mu[i] == 0)  continue;

        LL dx = 0;
        //Calculating D(X). Can be done naively, because [N/1] + [N/2] + [N/3] + ... + [N/N] -> N log N
        for(int j=i;j<=maxx;j+=i)
            dx += cnt[j];

        ans += mu[i] * (dx*(dx-1)*(dx-2)/6);
    }

    cout << ans << endl;

    return 0; 
}

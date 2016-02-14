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
#define MOD 1073741824

int pf(int n)
{
    int cnt;
    LL div=1;
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            div = (div * (cnt+1))%MOD;
        }
    if(n > 1)
        div = (div * 2)%MOD;

    return div;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    LL ans = 0;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k = 1;k<=c;k++)
            {
                ans = (ans + pf(i*j*k))%MOD;
            }

    cout<<ans<<endl;
    return 0; 
}

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
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#include <climits>

#define MAX 200010
#define MOD 1000000007
int arr[MAX];
int cnt[110][MAX];
LL cumm[110];
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return (result%MOD);
}
#define gc getchar_unlocked
inline void readNat(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimis
    //
    //printf("%lld\n",ans);ation
         for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
int main()
{
    int t,n,peek;
    LL ans;
    readNat(&t);
    while(t--)
    {
        memset(cnt,0,sizeof cnt);
        readNat(&n);
        for(int i=0;i<n;i++)
            readNat(&arr[i]);

        cnt[arr[0]][0] = 1;
        for(int j=1;j<n;j++)
        {
            for(int i=1;i<=100;i++)
                cnt[i][j] = cnt[i][j-1];      

            cnt[arr[j]][j] += 1;
        }

        
        ans = 1;
        for(int d=-100;d<=100;d++)
        {
            memset(cumm,0,sizeof(cumm));
            if(d != 0)
            {
                for(int i=0;i<n;i++)
                {
                    peek = arr[i]-d;
                    if(peek >= 1 && peek <= 100)
                    {
                        cumm[arr[i]] = (cumm[arr[i]] + cumm[peek] + cnt[peek][i])%MOD;
                        //ans = (ans+cumm[peek]+cnt[peek][i])%MOD;
                        //cout<<cumm[arr[i]]<<" ";
                    }
                }
                //cout<<endl;
                for(int i=1;i<=100;i++)
                    ans = (ans+cumm[i])%MOD;
            }
        }
        trace1(ans);        
        //for d == 0
        for(int i=1;i<=100;i++)
            ans = (ans + expo(2,cnt[i][n-1]) - 1 + MOD)%MOD;

        trace1(ans);
        ans =  (expo(2,n) - ans + MOD)%MOD;
        
        printf("%lld\n",ans);
    }
    return 0; 
}

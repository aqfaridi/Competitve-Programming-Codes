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
int arr[MAX],cnt[110], cumm[110],cumm2[110];
int expo(LL a,LL n)
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
int scan_d() 
{
    int ip=getchar_unlocked(),ret=0,flag=1;
    for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
    for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';
    return flag*ret;
}

void println_d(int n) 
{
    if(n<0){n=-n;putchar_unlocked('-');}
    int i=10;
    char output_buffer[11];
    output_buffer[10]='\n';
    do{output_buffer[--i]=(n%10)+'0';
        n/=10;}while(n);
    do{putchar_unlocked(output_buffer[i]);
    }while(++i<11);
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,minn,maxx,dmaxx,prev,next,ans;
    t = scan_d();
    while(t--)
    {
        minn = INT_MAX;
        maxx = INT_MIN;
        n = scan_d();
        for(int i=0;i<n;i++)
        {
            arr[i] = scan_d();
            minn = min(minn,arr[i]);
            maxx = max(maxx,arr[i]);
        }
        dmaxx = (maxx-minn);
        ans = 1;
        for(int d=0;d<=dmaxx;d++)
        {
            memset(cumm,0,sizeof(cumm));
            memset(cnt,0,sizeof(cnt));
            memset(cumm2,0,sizeof(cumm2));
            for(int i=0;i<n;i++)
            {
                prev = arr[i] - d;
                next = arr[i] + d;
                if(prev >= minn && prev <= maxx)
                    cumm[arr[i]] = ((cumm[arr[i]] + cumm[prev])%MOD + cnt[prev])%MOD;
                if(next >= minn && next <= maxx) 
                    cumm2[arr[i]] = ((cumm2[arr[i]] + cumm2[next])%MOD + cnt[next])%MOD;
                
                cnt[arr[i]]++;
            }
            if(d == 0)  memset(cumm2,0,sizeof(cumm2));
            for(int i=minn;i<=maxx;i++)
                ans = ((ans+cumm[i])%MOD + cumm2[i])%MOD;
        }
        ans = (ans + n)%MOD;
        ans =  (expo(2,n) - ans + MOD)%MOD;

        println_d(ans);
    }
    return 0; 
}

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
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n){
        if((n&1))
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return (result%MOD);
}
LL nCr(int n,int r)
{
    //n!/(r!*(n-r)!)
    LL Nr = 1, Dr = 1; 
    for(int i=0;i<r;i++){
        Dr *= (i+1);
        Nr = (Nr*(n-i))%MOD;
    }
    Dr = expo(Dr,MOD-2); 
    return (Nr*Dr)%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    LL ans;
    cin>>n;
    if(n < 13)  {   cout<<0<<endl; return 0;}

    n = (n-13)/2;
    ans = 0;
    for(int i=1;i<=min(7,n);i++){
            if(n-1 >= (i-1)){
                ans = (ans + (nCr(7,i) * nCr(n-1,i-1))%MOD)%MOD;
            }
    }
    if(ans == 0)
        cout<<1<<endl;
    else
        cout<<ans<<endl;
    return 0; 
}

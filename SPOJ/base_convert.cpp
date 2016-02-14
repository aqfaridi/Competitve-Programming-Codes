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

#define MAX 100010
#define MOD 1000000007
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
string str;
LL l,p;
LL decimal(int pos)
{
    LL pwr = 1;
    LL result = 0;
    for(int i = 0 ; i <= pos ; i++)
    {
        result += pwr*(str[i]-'0');        
        pwr *= p;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,rem,num,ans,N,sum,p_i;
    cin>>t;
    while(t--)
    {
        cin>>p>>n;
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            num = i;
            while(num)
            {
                rem = num%p;
                ans += rem;
                num /= p;
            }
        }
        cout<<ans<<endl;
    }
    return 0; 
}

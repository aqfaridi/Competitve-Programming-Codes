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

int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,Nr,Dr,x,a,d,N,g;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Dr = 6*n*n*n;
        if((n&1))
        {
            x = (n-1)/2;
            Nr = x*x + n*n + n;
            //a = 1 , d = 2 and # of terms=n/2
            a = 1;d = 2;N = n/2;
            Nr += N*(2*a+(N-1)*d)/2;
        }
        else
        {
            x = (n-1)/2;
            Nr = x*x + x + n*n + n;
            //a = 0 , d = 2 and # of terms=n/2
            a = 0;d = 2;N = n/2;
            Nr += N*(2*a+(N-1)*d)/2;
        }
        g = __gcd(Nr,Dr);
        cout<<Nr/g<<"/"<<Dr/g<<endl;
    }
    return 0; 
}

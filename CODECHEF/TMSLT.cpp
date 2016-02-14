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
    
#define print(x)                 cerr<<x<<" ";
#define pn()                     cerr << endl; 
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 3000010
#define MOD 1000000
LL S[MAX];
void precompute(int n,int a,int b,int c,int d)
{
    S[0] = d;
    for(int i=1;i<n;i++)
        S[i] = ((a*S[i-1]*S[i-1])%MOD + (b*S[i-1])%MOD + c)%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    int t,n,a,b,c,d;
    LL odd,even;
    cin>>t;
    while(t--)
    {
        odd = even = 0;
        cin>>n>>a>>b>>c>>d;
        precompute(n,a,b,c,d);
        sort(S,S+n);
        rep(i,n)
        {
            //print(S[i]);
            if(i&1)
                odd += S[i];
            else
                even += S[i];
        }
        cout<<abs(odd - even)<<endl;

    }
    return 0; 
}

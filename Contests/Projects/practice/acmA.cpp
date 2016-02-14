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
LL a[MAX] ;
int main()
{
    ios::sync_with_stdio(false);
    int toffee,x,t,n,rem,ans;
    bool b;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>x;
        rem = 0;
        b = false;
        rep(i,n){
            cin>>a[i];
            toffee = ((rem + a[i]) / x);
            if(toffee == 0)
                b = true;
            rem = (rem + a[i]) % x;
            ans += toffee;
        }
        if(b)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0; 
}


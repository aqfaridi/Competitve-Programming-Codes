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
LL cumm[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,l;
    LL ans;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>l;cin>>str;
        cumm[l] = 0;
        for(int i=l-1;i>=0;i--)
        {
            if(str[i] == '1')
                cumm[i] = 1 + cumm[i+1];
            else
                cumm[i] = cumm[i+1];
        }

        ans = 0;
        for(int i=0;i<l;i++)
            if(str[i] == '1')
                ans += cumm[i];

        cout<<ans<<endl;
    }
    return 0; 
}

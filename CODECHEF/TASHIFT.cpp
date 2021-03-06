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

int main()
{
    ios::sync_with_stdio(false);
    int n,cnt,shift = 0,ans = 0,maxx=0;
    string a,b,B;
    cin>>n;
    cin>>a>>b;
    B = b;
    do{
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<"--------"<<endl;
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == b[i])
                cnt++;
            else
                break;
        }
        
        if(cnt > maxx)
        {
            ans = shift;
            maxx = cnt;
        }

        shift++;
        b = b.substr(1) + b[0];
    }
    while(b != B);
    

    cout<<ans<<endl;
    return 0; 
}

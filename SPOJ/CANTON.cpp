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
    LL x,n,endp,diff;
    cin>>t;
    while(t--)
    {
        cin>>x;
        n = (int)ceil((sqrt(1+8*x) - 1)/2.0);
        if(n&1)
        {
            endp = n*(n+1)/2;
            diff = endp - x;
            cout<<"TERM "<< x <<" IS "<<diff + 1<<"/"<<n-diff<<endl;
        }
        else
        {
            n -= 1;
            endp = n*(n+1)/2;
            diff = x - endp;
            cout<<"TERM "<< x <<" IS "<<diff<<"/"<<n+2-diff<<endl;
        }
    }
    return 0; 
}

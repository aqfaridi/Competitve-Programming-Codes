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
LL a,b,x,y;
bool binary(LL mid){
   LL both = mid / (x*y) , p = mid/x , q = mid/y, P=0 , Q=0;   
   P = q - both;
   Q = p - both;
   LL rem = mid - (p + q - both);

   if( (b - Q) > 0)
       rem -= (b-Q);
   if( (a - P) > 0)
       rem -= (a-P);
   
   if(rem >= 0)
       return 1;
   else
       return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>x>>y;
    LL lo = 0,hi = (1LL<<60),mid;
    while(lo < hi){
        mid = (lo + hi)/2;
        if(binary(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout<<lo<<endl;
    return 0; 
}


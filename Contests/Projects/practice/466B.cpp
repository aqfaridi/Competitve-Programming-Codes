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
LL n,a,b,y,side_a,side_b;
bool binary(LL mid)
{
    y = max(0LL,(LL)ceil(6.0*n/(a+mid)) - b);
    cout<<(a+mid)*(b+y)<<" "<<6*n<<endl;
    cout<<a<<" "<<b<<" "<<n<<" "<<y<<endl;
    cout<< ((a+mid)*(b+y) >= 6*n)<<endl;
    return (a+mid)*(b+y) >= 6*n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    LL low = 0,high = 1e9,mid,minn = 1e18;
    while(low < high)
    {
        mid = (low+high)/2;
        trace3(low,mid,high);
        if(binary(mid)){
            if((a+mid)*(b+y) <= minn){
                minn = (a+mid)*(b+y);
                side_a = (a+mid);side_b = (b+y);
            }
            high = mid;
        }
        else 
            low = mid+1;
    }
    //LL x = low;
    //LL y = max(0LL,(LL)ceil(6.0*n/(a+x) - b));
    cout<<minn<<endl;
    cout<<side_a<<" "<<side_b<<endl;

    return 0; 
}

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
typedef unsigned long long LL;
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
LL dp[65];
void precalc()
{
    dp[0] = dp[1] = 0;
    dp[2] = 1;dp[3] = 3;
    for(int i=4;i<64;i++)
        dp[i] = (1LL<<(i-2)) + dp[i-1] + dp[i-2];
}
LL get_cuts(LL n)
{
   LL cuts = 0,prev = -5;
   for(int i = __lg(n);n>0;)
   {
        cuts += dp[i];
        prev = i;
        n ^= (1LL << i);
        if(n != 0)
        {
            i = __lg(n);
            //trace2(i,prev);
            if( i + 1 == prev)
            {   
                cuts += dp[i];
                n ^= (1LL << i);
                cuts += (n+1); 
                break;
            }
        }
   }
   return cuts;
}
int main()
{
    precalc();
    ios::sync_with_stdio(false);
    int t;
    string str;
    LL n,low,high,cuts,mid;
    cin>>t;
    while(t--)
    {
        str = "";
        cin>>n;
        low = 0;
        high = (1LL << 63);
        while(low <= high)
        {
            mid = (low + high)/2;
            cuts = get_cuts(mid);
            //trace2(mid,cuts);
            if(mid-cuts == n)
            {
                cuts = get_cuts(mid-1);
                //trace2(mid-1,cuts);
                if((mid - 1) - cuts != n)
                    break;
                else 
                    high = mid - 1;
            }
            else if(mid - cuts < n)
                low = mid + 1;
            else if(mid - cuts > n)
                high = mid - 1;
        }
        //cout<<mid<<endl;
        while(mid)
        {
            if(mid & 1)
                str += "1";
            else 
                str += "0";
            mid /= 2;
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0; 
}

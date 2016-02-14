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
int mem[1010][1010][2];
int solve(int a,int b,int p)
{
    if( a == 1 && b == 1 ) return 3;

    if(a == 1)   return 1;
    if(b == 1)   return 0;

    int& res = mem[a][b][p];
    if(res != -1)   return res;
    res = 1-p;

    if(p == 0)
    {
        int g = __gcd(a,b);
        if(g == 1)
            res = solve(a,b-1,1);
        else
        {
            if(b/g != 0)
                res = solve(a,b/g,1);
            res = (res & solve(a,b-1,1));
        }
    }
    else
    {
        int g = __gcd(a,b);
        if(g == 1)
            res = solve(a-1,b,0);
        else
        {
            if(a/g != 0)
                res = solve(a/g,b,0);

            if(res == 3)
                res = (res & solve(a-1,b,0)); 
            else            
                res = (res | solve(a-1,b,0));
        }
    }

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,a,b,ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        memset(mem,-1,sizeof mem);
        ans = solve(a,b,0);
        if(ans == 3)
            cout<<"Draw"<<endl;
        else if(ans == 0)
            cout<<"Arjit"<<endl;
        else
            cout<<"Chandu Don"<<endl;
    }
    return 0; 
}

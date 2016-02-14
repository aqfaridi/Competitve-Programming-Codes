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
LL mem[65][10];
int n;
LL solve(int idx,int profile)
{
    if(idx == n)    return 1;

    LL& res = mem[idx][profile];
    if(res != -1)   return res;
    res = 0;

    for(int i=profile;i<=9;i++)
        res += solve(idx+1,i);

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,cases;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>cases>>n;
        cout<<cases<<" "<<solve(0,0)<<endl;
    }
    return 0; 
}

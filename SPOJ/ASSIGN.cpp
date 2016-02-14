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
LL mem[(1<<20)];
int matr[25],n;
LL solve(int idx,int mask)
{
    if(idx == n)
    {
        if(mask == ((1<<n)-1))  return 1;
        else return 0;
    }

    LL& res = mem[mask];
    if(res != -1)   return res;
    res = 0;

    for(int i=0;i<n;i++)
        if((matr[idx]&(1<<i)) && ((mask&(1<<i))==0))
            res += solve(idx+1,mask|(1<<i));
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,var,k;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            k = 0;
            for(int j=0;j<n;j++)
            {
                cin>>var;
                if(var)
                    k |= (1<<j);
      
            }
            matr[i] = k;
        }
        cout<<solve(0,0)<<endl;
    }
    return 0; 
}

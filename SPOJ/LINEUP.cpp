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
#include <climits>
#define MAX 100010
#define MOD 1000000007
int mem[(1<<11)];
int matr[11][11],n;
int solve(int idx,int mask)
{
    if(idx == n)
    {
        if(mask == ((1<<n)-1))
            return 0;
        else
            return INT_MIN;
    }

    int& res = mem[mask];
    if(res != INT_MIN)   return res;

    for(int i=0;i<n;i++)
        if((matr[idx][i]>0) && ((mask&(1<<i))==0))
            res = max(res,matr[idx][i] + solve(idx+1,mask|(1<<i)));
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<(1<<11);i++)
            mem[i] = INT_MIN;

        n = 11;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matr[i][j];
        
        cout<<solve(0,0)<<endl;
    }
    return 0; 
}

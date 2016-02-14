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

#define MAX 1010
#define MOD 1000000007
int mem[MAX][MAX];
int L[MAX];
int solve(int i,int j)
{
    if(i+1 == j)    return 0;
    
    int& res = mem[i][j];
    if(res != -1)   return res;
    res = INT_MAX; //min. problem
    for(int k=i+1;k<j;k++)
        res = min(res,solve(i,k) + solve(k,j) + (L[j]-L[i]));
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)   cin>>L[i];
    L[0] = 0; L[m+1] = n;
    memset(mem,-1,sizeof mem);
    cout<<solve(0,m+1)<<endl;
    return 0; 
}

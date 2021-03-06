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

#define MAX 2010
#define MOD 1000000007
#define INF 1000000
int W,n;
int v[MAX],w[MAX];
int mem[MAX][MAX];
int solve(int idx,int filled)
{
    if(idx == n)
        return 0;

    int& res = mem[idx][filled];
    if(res != -1)   return res;
    res = INT_MIN;  //max prob

    if(filled+w[idx] <= W)
        res = max(res,v[idx] + solve(idx+1,filled+w[idx]));   
    res = max(res,solve(idx+1,filled));

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>W>>n;
    rep(i,n)    cin>>w[i]>>v[i];
    memset(mem,-1,sizeof mem);
    cout << solve(0,0) << endl;  
    return 0; 
}

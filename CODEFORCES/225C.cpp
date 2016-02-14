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
int n,m,x,y,nob,now;
string str[MAX];
int cost[2][MAX];
int mem[MAX][MAX][2];
int solve(int idx,int w,int pc)
{
    if(idx == m)
    {
        if(w >= x && w <= y)
            return 0;
        else
            return (1<<20);
    }

    int& res = mem[idx][w][pc];
    if(res != -1)   return res;

    if(w<x)
        res = cost[pc][idx] + solve(idx+1,w+1,pc);
    else if(w >=x && w < y)
        res = min(cost[pc][idx] + solve(idx+1,w+1,pc),cost[1-pc][idx] + solve(idx+1,1,1-pc));
    else
        res = cost[1-pc][idx] + solve(idx+1,1-pc,1);
        
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
        cin>>str[i];

    for(int j=0;j<m;j++){
        now = nob = 0;
        for(int i=1;i<=n;i++){
            if(str[i][j] == '.')
                now++;
            else if(str[i][j] == '#')
                nob++;
        }
        cost[0][j] = now;
        cost[1][j] = nob;
    }

    memset(mem,-1,sizeof mem);
    int m1 = solve(0,0,0);
    memset(mem,-1,sizeof mem);
    int m2 = solve(0,0,1);
    int ans = min(m1,m2);

    cout<<ans<<endl;
     
        
    return 0; 
}

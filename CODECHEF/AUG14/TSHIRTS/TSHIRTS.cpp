#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>
#include <cstring>

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
int mat[200][20];
vector<int> mt[200];
int mem[200][4096];
int n,maxt;
int solve(int idx,int profile)
{
    if(profile == ((1<<n)-1))
        return 1;
    if(idx == maxt+1)  return 0;
    
    int& res = mem[idx][profile];
    if(res != -1) return res;
    res = 0;

    res = solve(idx+1,profile)%MOD; // not weared
    for(int i=0;i<n;i++)
        if(mat[idx][i] && (profile&(1<<i))==0)
            res = (res + solve(idx+1,profile|(1<<i)))%MOD;
    
    return res%MOD;
}

int solve_fast(int idx,int profile)
{
    if(profile == ((1<<n)-1))
        return 1;
    if(idx == maxt+1)  return 0;
    
    int& res = mem[idx][profile];
    if(res != -1) return res;
    res = 0;
    
    res = solve_fast(idx+1,profile)%MOD; // not weared
    int size = mt[idx].size();
    for(int i=0;i<size;i++)
        if((profile&(1<<mt[idx][i]))==0)
            res = (res + solve_fast(idx+1,profile|(1<<mt[idx][i])))%MOD;
    
    return res%MOD;
}

int iterative_bottomup()
{
    mem[0][0] = 1;
    for(int idx=1;idx<=maxt;idx++)
    {
        for(int mask=0;mask<(1<<n);mask++)//all possible prev. profiles            
        {
            //state : (idx-1)  to   (idx)
            mem[idx][mask] = (mem[idx][mask] + mem[idx-1][mask])%MOD; // not weared
            for(int j=0;j<n;j++)
                if(mat[idx][j] && (mask&(1<<j)) == 0)
                    mem[idx][mask | (1<<j)] = (mem[idx][mask | (1<<j)] + mem[idx-1][mask])%MOD;
        }
    }
    return mem[maxt][(1<<n)-1];
}
 
int iterative_topdown()
{
    mem[maxt+1][(1<<n)-1] = 1;
    for(int idx=maxt;idx>=1;idx--)
    {
        for(int mask=0;mask<(1<<n);mask++)//all possible prev. profiles            
        {
            //state : (idx-1)  to   (idx)
            mem[idx][mask] = (mem[idx][mask] + mem[idx+1][mask])%MOD; // not weared
            for(int j=0;j<n;j++)
                if(mat[idx][j] && (mask&(1<<j)) == 0)
                    mem[idx][mask] = (mem[idx][mask] + mem[idx+1][mask|(1<<j)])%MOD;
        }
    }
    return mem[1][0];
}
int main()
{
    ios::sync_with_stdio(false);
    int t,tid;
    string str,s;
    string::size_type szz;
    cin>>t;
    getline(cin,s);
    while(t--)
    {
        memset(mem,0,sizeof mem);
        memset(mat,0,sizeof mat);
        //rep(i,200)
          //  mt[i].clear();

        cin>>n;
        maxt = -1;
        getline(cin,s);
        rep(i,n)
        {
            getline(cin,str);  
            stringstream ss(str);
            while(ss >> s)
            {
                stringstream st(s);
                st >> tid;
                //mt[tid].pb(i);
                maxt = max(maxt,tid);
                mat[tid][i] = 1;
            }
        }
        cout<<iterative_topdown()<<endl;
        //cout<<iterative_bottomup()<<endl;
        //cout << solve(0,0) << endl;
        //cout<<solve_fast(0,0)<<endl;
    }
    return 0; 
}

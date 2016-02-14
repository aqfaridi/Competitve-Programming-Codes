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
string str,ans;
int mem[2710][2710];
int cnt[26];
int solve(int x,int y)
{
    if(x > y)   return 0;
    if(x == y)  return 1;

    int& res = mem[x][y];
    if(res != -1)   return res;
    
    if(str[x] == str[y])
        res = 2 + solve(x+1,y-1);
    else
        res = max(solve(x+1,y),solve(x,y-1));
    return res;
}

int ptr;
void trace(int x,int y)
{
    if(x>y) return;
    if(x == y){  ans[ptr++] = str[x];}

    else if(str[x] == str[y])
    {
        ans[ptr++] = str[x];
        trace(x+1,y-1);
        ans[ptr++] = str[y]; 
    }
    else
    {
        if(mem[x+1][y] > mem[x][y-1])
            trace(x+1,y);
        else
            trace(x,y-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>str;
    int l = str.length();
    if(l >= 2700) // acc. to pigeonhole principle
    {
        rep(i,l)
            cnt[str[i]-'a']++;
        rep(i,26)
            if(cnt[i] >= 100)
            {
                rep(j,100)
                    cout<<(char)(i+'a');
                cout<<endl;
                return 0;
            }
    }
    
    memset(mem,-1,sizeof mem);
    solve(0,l-1);
    ptr = 0;
    trace(0,l-1);
    if(ptr <= 100)  rep(i,ptr) cout<<ans[i];
    else
    {
        for(int i=0;i<50;i++) cout<<ans[i];
        for(int i=ptr-50;i<ptr;i++) cout<<ans[i];
    }
    cout<<endl;
    return 0; 
}

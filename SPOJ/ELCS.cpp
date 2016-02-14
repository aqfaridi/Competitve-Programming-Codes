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

#define MAX 6610
#define MOD 1000000007
string str1,str2;
int n,m,maxx;
int mem[MAX][MAX];
int solve(int i,int j)
{
    if(i == n or j == m)
        return 0;
            
    int& res = mem[i][j];
    if(res != -1)   return res;

    if(str1[i] == str2[j])
        res = 1 + solve(i+1,j+1);
    else
        res = 0;
    
    solve(i+1,j);
    solve(i,j+1);

    maxx = max(maxx,res);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        maxx = 0;
        memset(mem,-1,sizeof mem);
        cin>>str2;
        str1 = str2;
        reverse(str2.begin(),str2.end());
        n = str1.length();
        m = n;
        solve(0,0);
        cout<<n-maxx<<endl;
    }
    return 0; 
}

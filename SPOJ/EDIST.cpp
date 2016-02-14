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
string str1,str2;
int n,m;
int mem[2010][2010];
int solve(int i,int j)
{
    if(i == n)
        return (m-j);//insert
    if(j == m)
        return (n-i);//delete 
    
    int& res = mem[i][j];
    if(res != -1)   return res;
    res = INT_MAX;

    if(str1[i] != str2[j]) //substitute
        res = 1 + solve(i+1,j+1);
    else
        res = solve(i+1,j+1);
    res = min(res,min(1+solve(i+1,j),1+solve(i,j+1)));//delete or insert
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>str1>>str2;
        n = str1.length();
        m = str2.length();
        cout<<solve(0,0)<<endl;
    }
    return 0; 
}

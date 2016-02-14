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
int n,k;
int mem[51][51][50010];
int arr[51];
int solve(int i,int j,int sum)
{
    if(i == n)  return 0;

    if(j == k-1)
        return mem[i][j][sum] = ((sum > arr[i])?1:0) + solve(i+1,j,sum);

    
    int& res = mem[i][j][sum];
    if(res != -1) return res;

    res = solve(i+1,j,sum) + solve(i+1,j+1,sum + arr[i]);
    
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n)    cin>>arr[i];
    sort(arr,arr+n);
    cin>>k;
    memset(mem,-1,sizeof mem);
    cout<<solve(0,0,0)<<endl;
    return 0; 
}


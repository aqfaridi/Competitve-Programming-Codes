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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int a[50],b[50],d[50][50];
int mem[(1<<25)],path[(1<<25)],n;
int solve(int mask){ 

    int& res = mem[mask];
    if(res != -1)   return res;

    int ret = 0,cost = 0;
    res = 1e9;
    for(int i=1;i<=n;i++)
        if(!(mask & (1<<i))){
            for(int j=i;j<=n;j++)
                if(!(mask & (1<<j))){
                    cost = d[0][i] + d[i][j] + d[j][0];
                    ret = cost + solve((mask | (1<<i) | (1<<j)));
                    if(ret < res){
                        res = ret;
                        path[mask] = (mask | (1<<j) | (1<<i));
                    }
                }
            break;//n ways for x & 1 way for y
        }
    if(res == 1e9)
        res = 0;

    return res; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a[0]>>b[0];
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>a[i]>>b[i];

    for(int i=0;i<=n;i++)    
        for(int j=0;j<=n;j++)
            d[i][j] = (a[i]-a[j])*(a[i]-a[j]) + (b[i]-b[j])*(b[i]-b[j]);

    memset(mem,-1,sizeof(mem));
    cout<<solve(0)<<endl;

    int cnt = 0;
    cout<<0;
    for(int mask = 0,prev = 0;;mask = path[mask]){
        if(cnt == n)    break;
        int temp = (path[mask] ^ prev);
        for(int i=0;i<=n;i++)
            if((temp & (1<<i))){
                cout<<" "<<i;
                cnt++;
            }
        cout<<" "<<0;
        prev = path[mask];
    }
    return 0; 
}


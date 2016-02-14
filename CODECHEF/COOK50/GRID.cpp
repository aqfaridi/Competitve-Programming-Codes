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

#define MAX 1020
#define MOD 1000000007
int arr[MAX][MAX];
int f[MAX][MAX];
int d[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof f);
        memset(d,0,sizeof d);
        memset(arr,0,sizeof arr); 

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>str;
            for(int j = 0;j<n;j++){
                if(str[j] == '.')
                    arr[i][j+1] = 1;
                else if(str[j] == '#')
                    arr[i][j+1] = 0;
            }
        }
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j] = arr[i][j] + f[i][j-1];

        for(int j=1;j<=n;j++)
            for(int i=0;i<=n;i++)
                d[i][j] = arr[i][j] + d[i-1][j];


        int cnt = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(arr[i][j]==1 && (f[i][n]-f[i][j] == (n-j)) && (d[n][j]-d[i][j] == (n-i)))
                   cnt++;
                
            }

        cout<<cnt<<endl;
    }
    return 0; 
}


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
LL g[22],n;
LL dp[(1<<20)][20];
LL iterative(){

    LL ans = 0;

    for(int i = 0;i<n;i++)
        dp[(1<<i)][i] = 1;
    
    for(int mask=0;mask<(1<<n);mask++){
        int s = __builtin_ctz(mask);
        for(int i=s;i<n;i++){ //prev
            if((mask&(1<<i)))
            for(int j=s;j<n;j++){ //next
                int nst = (mask | (1<<j));
                if(!(mask&(1<<j))  && (g[i] & (1<<j))){ //(i->j) edge  & (j) is not in mask 
                    dp[nst][j] += dp[mask][i];
                    if((g[j]&(1<<s)) && __builtin_popcount(nst) >= 3)//cycle check starts at (s) and ends at (j)
                        ans += dp[mask][i];
                }
            }
        }
    }

    return ans/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x -= 1; y -= 1;
        g[x] |= (1<<y);
        g[y] |= (1<<x); //undirected graph
    }

    cout<<iterative()<<endl; 
    
    return 0; 
}


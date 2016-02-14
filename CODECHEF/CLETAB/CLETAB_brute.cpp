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
int order[500],sit[500],m,n;
int solve(int idx,int profile)
{
    if(idx == m)
        return 0;
    

    int f = false;
    int res = 0;
    rep(i,n) {
        if(sit[i] == order[idx]){
            f = true;
            res += solve(idx+1,profile); 
            break;
        }    
        else if(sit[i] == 0){
            f = true;
            sit[i] = order[idx];
            res += 1 + solve(idx+1,profile | (1<<order[idx]));
            break;
        }
    }

    int ans = 100000;
    if(!f)
        rep(i,n){
            int temp = sit[i];
            sit[i] = order[idx];
            int p = (profile & ~(1<<temp));
            ans = min(ans,1 + solve(idx+1,p | (1<<order[idx])));
            sit[i] = temp;
        }
    else 
        return res;
    return ans;        
}
int idxb[500][500];
void pre()
{
    for(int i=m-1;i>=0;i--){
        for(int j=m;j>=1;j--)
            idxb[i][j] = idxb[i+1][j];
        idxb[i][order[i]] = i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,maxx,pos,ans;
    cin>>t;
    while(t--)
    {
        memset(idxb,31,sizeof idxb);
        cin>>n>>m;
        rep(i,m) cin>>order[i];
        pre();
        memset(sit,0,sizeof(sit)); ans = 0;
        cout << solve(0,0) << endl;
        memset(sit,0,sizeof(sit)); ans = 0;
        rep(i,m){
            rep(j,n)
                if(sit[j] == order[i])
                    goto down;
            rep(j,n)
                if(sit[j] == 0){
                    sit[j] = order[i];
                    ans++;
                    goto down;
                }
            maxx = -1;pos = 0;
            rep(j,n)
                if(idxb[i][sit[j]] > maxx){
                    maxx = idxb[i][sit[j]];
                    pos = j;
                }
            ans++ ;
            trace3(maxx,pos,order[i]);
            sit[pos] = order[i];
down: ;
      rep(j,n)
          cout<<sit[j]<<" ";
      cout<<endl;
        }
        cout<<ans<<endl;
        cout<<"------------------"<<endl;
    }
    return 0; 
}

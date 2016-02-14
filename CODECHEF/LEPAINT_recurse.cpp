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
int cnt[60];
double p[60][110];
int n,c,K;
double solve(int idx,int pc)
{
    if(idx == K+1)    return 1.0;

    double& res = p[idx][pc];
    if(res != -1) return res;
   
    res = 0.5 * solve(idx+1,pc);//not colored
    cout<<res<<endl;
    for(int i=1;i<=c;i++)
        if(i!=pc)
            res += (1.0/(2.0*c)) *  solve(idx+1,(pc*i)%c);
    cout<<res<<endl;
    cout<<"------------"<<endl;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,L,R;
    cin>>t;
    while(t--)
    {
        cin>>n>>c>>K;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=K;i++)
        {
            cin>>L>>R;
            for(int j=L;j<=R;j++)
                cnt[j]++;
        }
        
        rep(i,n+1)
            rep(j,c+1)
                p[i][j] = -1;

        /*
        memset(p,0,sizeof p);
        
        p[0][1] = 1;
        for(int i=1;i<=K;i++) // for all turns
            for(int j=0;j<=c;j++)//prev color
            {
                p[i][j] += p[i-1][j]/2.0;
                for(int k=0;k<=c;k++)//next coloring done
                    p[i][(j*k)%c] += (1.0/(2.0*c))*p[i-1][j];
            }
        */

        solve(0,1);
        rep(i,n+1){
            rep(j,c+1)
                cout<<p[i][j]<<" ";
            cout<<endl; 
        }
        double ans = 0;
        for(int i=1;i<=n;i++)
           for(int j=0;j<=c;j++)
               ans += j*p[cnt[i]][j];
        
        printf("%.9lf\n",ans);
        
    }
    return 0; 
}

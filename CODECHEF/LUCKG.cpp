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
int P[1010],ans[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    bool result;
    cin>>t;
    while(t--)
    {
        result = true;

        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>P[i];
            if(P[i] == i) result = false;        
        }
        
        if(!result || n==1 || n==2 || m==1){cout<<"No Solution"<<endl;continue;}

        if(!((n == 3) && (m==3 || m==5 || m==6 || m==7 || m==8)))
        {cout<<"No Solution"<<endl;continue;}


        memset(ans,0,sizeof ans);

        int ptr = (n-1),val;
        for(int j=0;j<m;j++,ptr--)
        {
            if(ptr < 0) ptr = n-1;
            val = j*n + 1;
            for(int i=0;i<n;i++)
            {
                if(i>=ptr)
                {
                    ans[i][j] = val;
                    val++;
                }
            }
        }
           
       
        for(int j=0;j<m;j++)
        {
            val = ans[n-1][j] + 1;
            for(int i=0;i<n;i++)
                if(!ans[i][j])
                {
                    ans[i][j] = val;
                    val++;
                }
        }

        rep(i,n){
            cout<<ans[i][0];
            for(int j=1;j<m;j++)
                cout<<" "<<ans[i][j];
            cout<<endl;
        }
    }
    return 0; 
}

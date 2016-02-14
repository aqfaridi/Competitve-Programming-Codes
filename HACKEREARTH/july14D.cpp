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
int x[60],y[60];
char c[60];
int mark[60];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,minn,idx;
    cin>>t;
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        cin>>n;
        rep(i,n)
            cin>>x[i]>>y[i]>>c[i];
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            minn = INT_MAX;
            idx = -1;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                if(abs(y[j]-y[i])  == abs(x[j]-x[i]) && !mark[j] && !mark[i])
                    if((c[i] == 'N' && (c[j] == 'E' || c[j] == 'W')) || (c[i] == 'S' && (c[j] == 'E' || c[j] == 'W')))
                    {                        
                        if(abs(y[j]-y[i]) < minn)
                        {
                            minn = abs(y[j]-y[i]);
                            idx = j;
                        }
                    }
            }
            if(idx != -1)
            {
                mark[idx] = 1;
                mark[i] = 1;
                cnt++;
            }
        }
        
        cout << n-cnt <<endl;
    }
    return 0; 
}

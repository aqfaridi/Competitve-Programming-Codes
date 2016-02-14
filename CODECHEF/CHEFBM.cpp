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
vector<int> v[MAX];
map<int,int> maps;
map<int,int>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,size,m,p,sum,a,b,f,s,m_size;
    bool flag;
    t = 1;
    while(t--)
    {
        cin>>n>>m>>p;
        sum = m-1;
        for(int i=0;i<MAX;i++)
            v[i].clear();
        rep(i,p)
        {
            cin>>a>>b;
            v[a].pb(b);
        }
        for(int i=1;i<=n;i++)
        {
            size = v[i].size();maps.clear();flag = true;
            for(int j=0;j<size;j++)
                maps[v[i][j]]++;
            int cnt = 0;
            for(int j=0;j<size;j++)
            {
                f = v[i][j];
                s = maps[f];                
                if(f != m && s > (maps[f+1]+1))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout<<sum-maps[1]+maps[m]<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0; 
}

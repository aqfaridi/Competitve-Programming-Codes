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

#define MAX 110
#define MOD 1000000007
string str[MAX];
vector<int> v;
int solve(int idx,int d)
{

}

int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>str[i];
        
        rep(i,n)rep(j,m)    if(str[i][j] == 'L')    v.pb(mp(i,j));
        


        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='L'){
                    for(int k=0;k<m;k++)
                        if(str[i][k] == 'E')
                            str[i][k] = '.';
                    for(int k=0;k<i;k++)
                        if(str[k][j] == 'E')
                            str[k][j] = '.';
                }                
            }

        int cnt = 0;
        rep(i,n)
            rep(j,n)
                if(str[i][j] == 'E')
                { cnt = 1;break;}

        if(cnt==0)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0; 
}

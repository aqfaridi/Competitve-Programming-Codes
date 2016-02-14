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
string str[11020];
int n,cnt;
bool visited[11020];
vector<int> v[11];
int cur,maxx;
void solve(int i)
{
    v[cur].pb(i);
    visited[i] = 1;
    for(int j=0;j<n;j++)
    {
        if(visited[j] == 0 && str[i][str[i].length()-1] == str[j][0])
        {
            solve(j);
            break;
        }
        cnt++;
    }
    if(cnt > (1<<24))   return;
}
int main()
{
    ios::sync_with_stdio(false);    
    int out;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
  
    for(int i=0;i<min(10,n);i++)
    {
        cur = i;
        solve(i);
        if(maxx < v[cur].size())
        {
            maxx = v[cur].size();
            out = cur;
        }
        memset(visited,0,sizeof(visited));
    }

    for(int i=0;i<maxx;i++)
        cout<<str[v[out][i]]<<endl;

    return 0; 
}

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
int n,maxx,cnt;
vector<int> start[26],end[26],ans;
int m[11020];

void solve(int ch,vector<int> perm)
{
    if(cnt > 400000000)   return;
    
    int idx,size = v[ch].size();
    bool flag = false;
    for(int i=0;i<size;i++)
    {
        cnt++;
        idx = v[ch][i];
        if(m[idx] == 0)
        {
            flag = true;
            perm.push_back(idx);
            m[idx] = 1;
            solve((str[idx][str[idx].length()-1]-'A'),perm);
            perm.pop_back();
            m[idx] = 0;
        }
    }
    if(!flag)
        if(perm.size() > maxx)
        {
            maxx = perm.size();
            ans = perm;
        }        

}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        start[(str[i][0]-'A')].pb(i);
    }
    
    for(int i=0;i<n;i++)
        end[str[i][str[i].length()-1]-'A'].pb(i);
        
    

    vector<int> temp;
   
    solve(str[0][0]-'A',temp);
    
    for(int i=0;i<maxx;i++)
        cout<<str[ans[i]]<<endl;

    return 0; 
}

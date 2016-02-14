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
#define INF 522133279
#define MOD 1000000007
vector<int> idx[20];
int arr[MAX];
int minjumps[MAX];
int mark[20];
int l;

int BFS(int index)
{
    int u,size,cnt,jump;
    queue< pii > q;
    q.push(make_pair(index,0));

    while(!q.empty())
    {
        u = q.front().first;
        cnt = q.front().second;
        q.pop();

        //trace2(u,cnt);
        if(minjumps[u] != INF)
            continue;

        //cout<<"here"<<endl;
        minjumps[u] = cnt;
        
        if(u == l-1)    return cnt;            

        size = idx[arr[u]].size();
        if(!mark[arr[u]])
        {
            for(int i=0;i<size;i++)
            {            
                jump = idx[arr[u]][i];
                if(minjumps[jump] == INF)
                    q.push(make_pair(jump,cnt+1));
            }
        }

        mark[arr[u]] = 1;
        if(u+1 < l && minjumps[u+1] == INF)
            q.push(make_pair(u+1,cnt+1));
        if(u-1 >= 0 && minjumps[u-1] == INF)
            q.push(make_pair(u-1,cnt+1));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(minjumps,31,sizeof(minjumps));
    string str;
    cin>>str;
    l = str.length();
    for(int i=0;i<l;i++)
    {
        idx[str[i]-'0'].pb(i);
        arr[i] = str[i] - '0';
    }
    cout << BFS(0) << endl;
    return 0; 
}

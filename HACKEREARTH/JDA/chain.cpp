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

#define MAX 11010
#define MOD 1000000007
string str[MAX];
vector<int> adjList[MAX];
bool visited[MAX];
int maxi;
vector<int> ans;

void DFS(int node,int cnt,vector<int> perm)
{
    if(maxi > 3500) return;

    visited[node] = true;
    perm.push_back(node);
    int size = adjList[node].size();
    bool flag = false;
    for(int i=0;i<size;i++)
        if(!visited[adjList[node][i]])
        {
            flag = true;
            DFS(adjList[node][i],cnt+1,perm);
        }

    if(!flag && cnt>maxi)
    {
        maxi = cnt;
        ans = perm;
    }
    perm.pop_back();
    visited[node] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        	if(i!=j)
                if(str[i][str[i].length()-1] == str[j][0])
                    adjList[i].pb(j);
   
    
    int maxx = adjList[0].size(),idx=0;
    for(int i=0;i<n;i++)
        if(adjList[i].size() < maxx && adjList[i].size() > 0)
        {
            maxx = adjList[i].size();
            idx = i;
        }

    DFS(idx,0,vector<int>());
    
    for(int i=0;i<=maxi;i++)
        cout<<str[ans[i]]<<endl;
    
    return 0; 
}

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
}
int mark[MAX],indeg[MAX],outdeg[MAX];
string same[MAX];
vector<int> actual;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
   
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i != j)
                if(str[i][str[i].length()-1] == str[j][0])
                {indeg[j]++,outdeg[i]++;}
    for(int i=0;i<n;i++)
        if(indeg[i] != outdeg[i])
            mark[i] = 1;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i != j && !mark[i] && !mark[j])
                if(str[i][str[i].length()-1] == str[j][0])
    
    DFS(2,0,vector<int>());

    for(int i=0;i<ans.size();i++)
        cout<<str[ans[i]]<<endl;
    
    return 0; 
}

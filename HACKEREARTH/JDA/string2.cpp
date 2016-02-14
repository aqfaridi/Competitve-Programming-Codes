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
vector<int> start[26],start2[26];
vector<int> res,res2,temp,it(26);
vector<int> same[26];
int mark[MAX];
vector<int> adjList[MAX];
bool visited[MAX];
vector<int> ans;
int maxi;
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

int main()
{
    ios::sync_with_stdio(false);
    int n,size1,size2,row,a,idx,maxx,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        start[str[i][0] - 'A'].push_back(i);
    }
     
    for(int i=0;i<26;i++)
    {
        temp.clear();
        it.assign(26,0);
        row = i; //row
        while(it[row] < start[row].size())
        {
            maxx = 0;
            idx = it[row];
            ele = start[row][it[row]];
            for(int j=it[row];j<start[row].size();j++)
            {
                a = start[row][j];
                if((start[str[a][str[a].size()-1]-'A'].size() - it[str[a][str[a].size()-1]-'A']) >= maxx)
                {
                    maxx = start[str[a][str[a].size()-1]-'A'].size() - it[str[a][str[a].size()-1]-'A'];
                    ele = a;
                    idx = j;
                }
            }
            swap(start[row][it[row]],start[row][idx]);
            temp.push_back(ele);
            int store = row;
            //update row
            row = str[ele][str[ele].size()-1]-'A';
            it[store]++;

        }
        size1 = temp.size();
        size2 = res.size();
        if(size1 > size2)
            res = temp;
    }

    for(int i=0;i<res.size()-5;i++)
        mark[res[i]] = 1;

    for(int i=0;i<n;i++)
        if(!mark[i])
            start2[str[i][0] - 'A'].push_back(i);

    for(int i=0;i<26;i++)
    {
        temp.clear();
        it.assign(26,0);
        row = i; //row
        while(it[row] < start2[row].size())
        {
            maxx = 0;
            idx = it[row];
            ele = start2[row][it[row]];
            for(int j=it[row];j<start2[row].size();j++)
            {
                a = start2[row][j];
                if((start2[str[a][str[a].size()-1]-'A'].size() - it[str[a][str[a].size()-1]-'A']) >= maxx)
                {
                    maxx = start2[str[a][str[a].size()-1]-'A'].size() - it[str[a][str[a].size()-1]-'A'];
                    ele = a;
                    idx = j;
                }
            }
            swap(start2[row][it[row]],start2[row][idx]);
            temp.push_back(ele);
            int store = row;
            //update row
            row = str[ele][str[ele].size()-1]-'A';
            it[store]++;

        }
        size1 = temp.size();
        size2 = res2.size();
        if(size1 > size2)
            res2 = temp;
    }
    assert(res2.size() > 200);
    for(int i=0;i<res.size();i++)
        cout<<str[res[i]]<<endl;
    return 0; 
}

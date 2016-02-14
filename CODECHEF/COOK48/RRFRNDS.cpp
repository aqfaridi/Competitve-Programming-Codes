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

#define MAX 2010
#define MOD 1000000007
int arr[MAX][MAX];
int parent[MAX];
int find(int x)
{
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}
int mark[2010][2010];
vector<int> v[2010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string str;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        parent[i] = i;
        for(int j=1;j<=n;j++)
        {
            arr[i][j] = str[j-1]-'0'; 
            //if(arr[i][j])   mark[i][j] = 1;
            if(arr[i][j])
                v[i].push_back(j);
        }
    }

/*
    int cnt2 = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(arr[i][j] == 0 && i!=j)
            for(int k=1;k<=n;k++)
                    if(i!=k && j!=k && arr[i][k] == arr[j][k] && arr[i][k] == 1)
                    {
                        cout<<i<<" "<<k<<" "<<j<<endl;
                        cnt2++;
                        break;
                    }
    cout<<"cnt="<<cnt2<<endl;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].size();j++)
              cout<<v[i][j]<<" ";
        cout<<endl;
    }
    //union find

    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
            if(arr[i][j])
                parent[i] = j;//find(j);
  */

    queue<int> q;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        //cout<<"i"<<i<<endl;
        
        for(int j=0;j<v[i].size();j++)
        {
            q.push(v[i][j]);
            parent[v[i][j]] = i;
        }
        while(!q.empty())
        {
            //cout<<"i="<<i<<endl;
            int child = q.front();
            q.pop();
            //cout<<"size="<<v[child].size()<<" "<<child<<endl;
            for(int j=0;j<v[child].size();j++)
            {
                if(v[child][j] == i)    continue;
                //cout<<"iii"<<i<<" "<<v[child][j]<<" "<<mark[i][v[child][j]]<<" "<<arr[i][v[child][j]]<<endl;
                if(!mark[i][v[child][j]] && arr[i][v[child][j]] == 0) {
                    //cout<<i<<" "<<v[child][j]<<endl;
                    cnt+=2;
                    mark[i][v[child][j]] = 1;
                    mark[v[child][j]][i] = 1;
                }
            }       
        }
    }
    cout<<cnt<<endl;
    return 0; 
}

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
vector<int> idx[20];
int minjumps[MAX];
int arr[MAX];
int mark[20];
int main()
{
    ios::sync_with_stdio(false);
    memset(minjumps,31,sizeof(minjumps));
    int INF = 522133279;

    int l;
    string str;
    cin>>str;
    l = str.length();
    for(int i=0;i<l;i++)
    {
        idx[str[i]-'0'].pb(i);
        arr[i] = str[i] - '0';
    }
   
    minjumps[0] = 0;
    int size = idx[arr[0]].size();
    for(int j=1;j<size;j++)
    {
        minjumps[idx[arr[0]][j]] = 1;

        for(int k=1;k<=10;k++)
            if(idx[arr[0]][j] + k < l)
                minjumps[idx[arr[0]][j] + k] = min(minjumps[idx[arr[0]][j] + k] , minjumps[idx[arr[0]][j]]+k); 
    
        for(int k=1;k<=10;k++)
            if(idx[arr[0]][j] - k >= 0)
                minjumps[idx[arr[0]][j] - k] = min(minjumps[idx[arr[0]][j] - k] , minjumps[idx[arr[0]][j]]+k);     
    }
    minjumps[1] = 1;


    mark[arr[0]] = 1;
    for(int i=1;i<l;i++)
    {
        if(mark[arr[i]] == 0)
        {
            if(minjumps[i] > min(minjumps[i-1],minjumps[i+1])+1)
                minjumps[i] = min(minjumps[i-1],minjumps[i+1]) + 1;

            if(minjumps[i+1] == INF)
                minjumps[i+1] = minjumps[i] + 1;

            size = idx[arr[i]].size();
            for(int j=0;j<size;j++)
                if(idx[arr[i]][j] > i)
                {
                    minjumps[idx[arr[i]][j]] = minjumps[i] + 1;

                    for(int k=1;k<=10;k++)
                        if(idx[arr[i]][j] + k < l)
                            minjumps[idx[arr[i]][j] + k] = min(minjumps[idx[arr[i]][j] + k] , minjumps[idx[arr[i]][j]]+k); 
                
                    for(int k=1;k<=10;k++)
                        if(idx[arr[i]][j] - k >= 0)
                            minjumps[idx[arr[i]][j] - k] = min(minjumps[idx[arr[i]][j] - k] , minjumps[idx[arr[i]][j]]+k);     
                }
            
            mark[arr[i]] = 1;
        }

    }
    /* 
    for(int i=0;i<l;i++)
        cout<<minjumps[i]<<" ";
    cout<<endl;
    */
    cout<<minjumps[l-1]<<endl;

    return 0; 
}

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

int a[110][10010];
vector<int> v[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int m,n,ans;
    char ch;
    cin>>n>>m;
    bool b = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ch;
            a[i][j]=(int)(ch-48);
            if(a[i][j]== 1)
                v[i].push_back(j);
        }
        if(v[i].size() == 0)
            b = false;        
    }
    int minn = (1<<30);
    if(!b) { cout<<-1<<endl;return 0;}
    for(int j=0;j<m;j++){
        ans = 0;
        for(int i=0;i<n;i++){
            if(a[i][j] == 1)continue;
            else{
                //size 1 check
                if(v[i].size() == 1)
                {
                    if(j <= v[i][0])
                        ans += min(abs(v[i][0] -j),abs(m+j-v[i][0]));
                    else  
                        ans += min(abs(v[i][0] -j),abs(m-j+v[i][0]));
                    continue;
                }

                int idx = upper_bound(v[i].begin() , v[i].end() , j) - v[i].begin();
                if(idx == v[i].size())
                    ans += min(abs(v[i][v[i].size()-1] -j) , abs(m-j+v[i][0]));                
                else if(idx > 0)
                    ans += min(abs(v[i][idx]-j) ,abs(j-v[i][idx-1]));
                else if(idx == 0)
                    ans += min(abs(v[i][idx]-j) , abs(m + j - v[i][v[i].size()-1]));               
            }
        }
        minn = min(minn,ans);
    }
                
    cout<<minn<<endl;
    return 0; 
}

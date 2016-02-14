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

#define MAX 1010
#define MOD 1000000007
int cnt[MAX],cnt_b[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        memset(cnt_b,0,sizeof(cnt_b));
        cin>>str;
        int l = str.length();
        for(int i=1;i<=l;i++){
            if(str[i-1] == '>')
                cnt[i] = cnt[i-1]+1;
            else
                cnt[i] = cnt[i-1];
        }

        for(int i=l;i>=1;i--){
            if(str[i-1] == '<')
                cnt_b[i] = cnt_b[i+1] + 1;
            else
                cnt_b[i] = cnt_b[i+1];
        }

        int maxx = 0,eq;
        for(int i=0;i<=l;i++)
            if(cnt[i] > 0 && cnt_b[i+1] > 0){
                eq = min(cnt[i],cnt_b[i+1]);
                maxx = max(maxx,2*eq);
            }
      
        cout<<maxx<<endl;
    }
    return 0; 
}

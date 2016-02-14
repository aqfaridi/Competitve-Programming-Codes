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
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    LL n,N,h;
    cin>>h>>n;
    N = n;
    while(n != 1){
        v.pb(n);
        n/=2;
    }
    reverse(all(v));
    int size = v.size();
    int init = 1;
    LL cnt = 1;
    int prev = -1;
    if(v[0] == 3) 
        prev = 2;
    for(int i=0;i<size;i++){
        trace1(v[i]);
        if(v[i] == 2*init){ // left 
            cnt++;
            if(prev == 1){
                int l = log2(v[i]);
                int arg = h - l + 1;
                trace1(arg);
                cnt += ((1LL<<arg) - 1);
            }
            init = v[i];
            prev = 1;
        }
        else{
            cnt++;
            if(prev == 2){
                int l = log2(v[i]);
                int arg = h - l + 1;
                trace1(arg);
                cnt += ((1LL<<arg) - 1);
            }
            trace1(cnt);
            init = v[i];
            prev = 2;
        }
    }
    cout<<cnt<<endl;
    return 0; 
}

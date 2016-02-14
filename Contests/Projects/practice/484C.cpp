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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
LL l,r;
int mem[110],path[110];
LL pwr[64];
void pre(){
    for(int i=0;i<=60;i++)
        pwr[i] = (1LL << i);
}

int solve(int i,LL val){
    
    if(i == -1) return 0;

    int& res = mem[i];
    if(res != -1)   return res;
    
    res = solve(i-1,val);
    if(l <= (val+pwr[i]) && (val+pwr[i]) <= r){
        int temp = 1 + solve(i-1,val+pwr[i]);
        if(temp > res){
            res = temp;
            path[i] = 1;
        }
    }

    return res;
}
int main()
{
    pre();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        cin>>l>>r;
        memset(path,0,sizeof path);
        memset(mem,-1,sizeof mem);
        cout<<solve(60,0)<<endl;
        for(int i=60;i>=0;i--)
            cout<<path[i];
    }
    return 0; 
}


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
int arr[51];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n,N;
int mem[51][(1<<15)];
int m[51];
vector<int> v;

int solve(int i,int mask){

    if(i == N)  return 0;  

    int& res = mem[i][mask];
    if(res != -1)   return res;
    
    if((m[i] & mask) == 0)// can take ith item in the set
        res = 1 + solve(i+1,mask | m[i]);
    
    res = max(res,solve(i+1,mask));
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    bool f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        memset(m,0,sizeof(m));

        rep(i,n){
            cin>>arr[i];
            f = false;
            rep(j,25)
                if(arr[i] > 50 && primes[j] == arr[i])
                {  f = true;break; }
            if(!f)
                v.pb(arr[i]);
        }
        
        N = v.size();
        for(int i=0;i<N;i++)
            for(int j=0;j<15;j++)
                if(v[i] % primes[j] == 0)
                    m[i] |= (1<<j);

        memset(mem,-1,sizeof mem);
        cout<<(n-N) + solve(0,0)<<endl;
    }
    return 0; 
}


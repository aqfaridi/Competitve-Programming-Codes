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

#define MAX 1100
#define MOD 1000000007
long long fib[MAX];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int s,k,cnt=0,sm;
    cin>>s>>k;
    sm = s;
    fib[1]= 1;
    for(int i=2 ;fib[i-1]<=s;i++){
        for(int j=i-1;(j >=(i-k) and j>= 1);j--)
            fib[i] += fib[j];
        cnt = i;
    }

    v.push_back(0);
    for(int i=cnt;i>=1 and sm>0 ;i--){
        if(fib[i]<=sm){
            v.push_back(fib[i]);
            sm -= fib[i];
        }
        if(sm<=0)break;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)cout<<v[i]<< " ";
    cout<<endl;
    return 0; 
}

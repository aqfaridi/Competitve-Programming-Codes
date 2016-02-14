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
vector<LL> v;
LL sumdig(LL n){
    LL sum=0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main()
{
    LL a,b,c;
    LL vl,n,cnt=0;
    cin>>a>>b>>c;
    for(int sm=1;sm<=81;sm++){     
        vl = 1;
        for(int i=1;i<=a;i++)
            vl *= sm;
        n = vl*b+c;
       if(n<=0)continue;
        if(n>= 1e9)continue;
        if(n<1000000000 && sumdig(n) == sm){
            cnt++;
            v.pb(n);
        }
    }
    sort(v.begin() , v.end());
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++) cout<<v[i]<<" ";
    cout<<endl;
    
    return 0; 
}

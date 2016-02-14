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

bool cmp(pii p1 , pii p2){

    if(p1.first == p2.first)
            return (p1.second > p2.second);
    else
           return (p1.first < p2.first);
}
int a[MAX];
vector < pii > v;
map<int,int> m;
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    //cin>>t;
    //while(t--)
    
        cin>>n;
        rep(i,n){
            cin>>a[i];
            v.pb(mp(a[i],i));
            m[a[i]] = max(m[a[i]],i);
        }
    
   
    sort(all(v));

      rep(i,n){
          pii p = v[i];
          if(p.second != i){
             //cout<<a[i]<<" "<<a[m[p.first]]<<endl;
             swap(a[i],a[m[p.first]]);
             break;
          }
      }
      bool b = true;
     //<F4>< rep(i,n)cout<<a[i]<<" " ;cout<<endl;
      rep(i,n){
          if(v[i].first != a[i]){
              cout<<"NO"<<endl;
              b = false;
              break;
          }
      }

      if(b)cout<<"YES"<<endl;

    return 0; 
}


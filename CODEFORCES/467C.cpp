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
typedef pair<LL,LL> pii;
typedef pair < pii,LL > tri;
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
LL arr[MAX],cumm[MAX],ans[MAX]; 
vector<tri> v;
bool cmp(tri a,tri b){
    return (a.first.second < b.first.second);
}
int optimal[10000];
vector<LL> ret;
int main(){
    ios::sync_with_stdio(false);
    int n,m,k;
    LL l,r,sum;
    cin>>n>>m>>k;
    cumm[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cumm[i] = cumm[i-1] + arr[i];
    }
   
    //choose l,r
    for(int i=1;i<=(n-m+1);i++){
        l = i;
        r = i+m-1;
        sum = cumm[r] - cumm[l-1];
        v.pb(mp(mp(l,r),sum));
    }
    
    sort(v.begin(),v.end(),cmp);

    ans[0] = 0;
    int size = v.size();
    bool f;

    rep(i,10000) optimal[i] = i;

    for(int i=0;i<size;i++){
        f = false;
        for(int j=i-1;j>=0;j--){
            if(v[j].first.second < v[i].first.first){
                if(ans[j] + v[i].second > ans[i-1]){
                    trace2(i,j);
                    ans[i] = ans[j] + v[i].second;
                    optimal[i] = j;
                }
                else{
                    trace2(i,i-1);
                    ans[i] = ans[i-1];
                    optimal[i] = (i-1);
                }
                f = true;
                break;
            }
        }
        if(!f){
            if(v[i].second > ans[i-1]){
                ans[i] = v[i].second;
            }
            else{
                ans[i] = ans[i-1];
                optimal[i] = (i-1);
            }
        }
    }

    int i = size-1;  

    while(optimal[i] != i)
    {
       cout << v[i].first.first << " " << v[i].first.second << " "<<v[i].second<<endl;
        ret.pb(v[i].second);
        i = optimal[i];
        cout<<i<<endl;
    }

    cout << v[i].first.first << " " << v[i].first.second << " "<<v[i].second<<endl;
    ret.pb(v[i].second);
    LL yy = 0;
    sort(ret.rbegin(),ret.rend());
    for(int i=0;i<k;i++)
        yy += ret[i];
    cout<<yy<<endl;
   // for(int i=0;i<size;i++) cout<<ans[i]<<" ";
   // cout<<endl;
   
    return 0; 
}


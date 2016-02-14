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
vector< pii > v;
int x[MAX],y[MAX],arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.pb(mp(arr[i],i));
    }
    sort(all(v));
    int idx=0,cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i].second != i){
            x[idx] = i;
            y[idx++] = v[i].second;
            cnt++;
            for(int j=0;j<n;j++)
                if(v[j].second == i){
                    v[j].second = v[i].second;
                    break;
                }
            v[i].second = i;
        }
        sort(all(v));
    }
    int ans = 0;
    bool f = true;
    for(int i=0;f && i<idx;i++){
        swap(arr[x[i]],arr[y[i]]);
        ans++;
        f = false;
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i])
            {
                f = true;
                break;
            }
        }
    }

    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
        cout<<x[i]<<" "<<y[i]<<endl;
    return 0; 
}

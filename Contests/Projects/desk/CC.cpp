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

int m[MAX],mark[MAX];
int pos[MAX],n,k;
bool binary(int mid){
        memset(mark,0,sizeof(mark));
        for(int i=0;i<n;i++){
            int idx = lower_bound(pos,pos+k,m[i]-mid)-pos;
            while(idx < k && mark[idx])
                idx++;
            mark[idx] = 1;
        }
        int cnt = count(mark,mark+k,1);
        for(int i=0;i<10;i++)  cout<<mark[i]<<" ";
        cout<<cnt<<endl;
        if(cnt == k)
            return  1;
        else
            return 0;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        rep(i,n)cin>>m[i];
        rep(i,k)cin>>pos[i];
        sort(m,m+n);sort(pos,pos+k);
        
        int low = 0, high = 1e9,mid;
        while(low < high){
            mid = (low  + high)/2;
            cout<<low <<" "<<mid<<" "<<high<<endl;
            if(binary(mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        cout<<low<<endl;

    }
    return 0; 
}

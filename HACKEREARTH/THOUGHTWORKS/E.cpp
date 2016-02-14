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
int arr[MAX];
vector< pii > tmp;
int main()
{
    ios::sync_with_stdio(false);
    int t,pos,n,cnt,k,maxx;
    bool f;
    cin>>t;
    while(t--)
    {
        tmp.clear();
        cin>>n>>k;
        rep(i,n)  {   cin>>arr[i]; tmp.pb(mp(arr[i],i));}
        sort(tmp.begin(),tmp.end());

        pos = 0,maxx = 0;
        for(int i=0;i<n;i++)
        {
            if(tmp[i].first == arr[pos]) { pos++; continue; }
            if(k - (tmp[i].second-pos) >= 0) 
            {

                k -= (tmp[i].second-pos);
                int j;
                if(tmp[i].second <= maxx)
                    j = tmp[i].second + pos;
                else 
                    j = tmp[i].second;
                for(;j>pos;j--)
                    swap(arr[j],arr[j-1]);
                
                pos++;
                if(tmp[i].second > maxx)
                    maxx = tmp[i].second;
            }
        }

        rep(i,n)    cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0; 
}

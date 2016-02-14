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

#define pb push_back
#define mp make_pair
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int arr[400];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    int maxx,minn = INT_MAX;
    for(int i=1;i<n-1;i++){
        v.clear();
        maxx = INT_MIN;
        for(int j=0;j<n;j++){
            if(j==i)    continue;
            v.pb(arr[j]);
        }
        
        int size = v.size();
        for(int j=1;j<size;j++){
            maxx = max(maxx,v[j] - v[j-1]);
        }
        minn = min(minn,maxx);
    }
    cout<<minn<<endl;    
    return 0; 
}


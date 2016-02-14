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

#define MAX 1000020
#define MOD 1000000007
LL arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,k,max_idx,maxx,minn,min_idx;
    t = 1;
    while(t--)
    {
        cin>>n>>k;
        rep(i,n)    cin>>arr[i];
        if(k == 0)
        {
            cout<<arr[0];
            for(int i=1;i<n;i++)
                cout<<" "<<arr[i];
            continue;
        }
        max_idx = max_element(arr,arr+n)-arr;
        min_idx = min_element(arr,arr+n)-arr;
        maxx = arr[max_idx];
        minn = arr[min_idx];
        if((k&1))
        {
            cout<<maxx-arr[0];
            for(int i=1;i<n;i++)
                cout<<" "<<maxx-arr[i];
        }
        else
        {
            cout<<arr[0]-minn;
            for(int i=1;i<n;i++)
                cout<<" "<<arr[i] - minn;
        }
    }
    return 0; 
}

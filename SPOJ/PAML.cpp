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

#define MAX 100010
#define MOD 1000000007
int arr[110],h[110];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,cnt,cases=0,height,k,idx;
    cin>>t;
    while(t--)
    {
        cases++;
        memset(h,0,sizeof(h));
        k = 0;
        cin>>n;
        rep(i,n)
            cin>>arr[i];
        sort(arr,arr+n);
        while(1)
        {
            
            height = cnt = 0;
            rep(i,n)
                if(arr[i] < 0)
                    cnt++;
            if(cnt == n)
                break;

            rep(i,n)
                if(arr[i] >= 0)
                {
                    idx = i;
                    height = 1;
                    arr[i] = -1;
                    break;
                }
            for(int i=idx + 1;i<n;i++)
            {
                if(height <= arr[i])
                {
                    //trace2(arr[i],height);
                    arr[i] = -1;
                    height++;
                }
            }
            h[k++] = height;
        }
        cout<<"Case #"<<cases<<": "<<k<<" "<<*max_element(h,h+k)<<endl;
    }
    return 0; 
}

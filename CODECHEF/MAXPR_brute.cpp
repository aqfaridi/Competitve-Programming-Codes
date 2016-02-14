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
int arr[32];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
               
        int cnt = 0;
        for(int i=0;i<(1<<n);i++)
        {
            v.clear();
            trace2(i,n);
            for(int j=0;j<n;j++)
                if((i&(1<<j)))
                    v.pb(arr[j]);
 
            int size = v.size();
            if(size == 0)
            {
                cnt++;
                cout<<"empty"<<endl;
                cout<<"-------------------"<<endl;
                continue;
            }
            if(size == 1)
            {
                cout<<v[0]<<endl;
                cout<<"-------------------"<<endl;
                cnt++;
                continue;
            }
            int d = v[1] - v[0];
            int prev = v[0];
            int cnt2 = 0;
            trace2(d,prev);
            for(int k=1;k<size;k++)
            {
                trace3(v[k],prev,d);
                if(v[k]-prev == d)
                    cnt2++;
                prev = v[k];
            }
            if(cnt2 == size-1)
            {
                cnt++;
                for(int k=0;k<size;k++)
                    cout<<v[k]<<" ";
                cout<<endl;
            }
            cout<<"------------------------"<<endl; 
        }
        trace1(cnt);

        int ans = pow(2,n) - cnt;
        trace1(ans);
    }
    return 0; 
}

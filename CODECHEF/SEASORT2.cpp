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
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 10010
#define MOD 1000000007
int arr[MAX],n;
vector<int> v;
int x[MAX],y[MAX];
bool isSorted()
{
    int i;
    for(i=1;i<n;i++)
        if(arr[i] > arr[i+1])
            break;
    return (i == n);
}
int main()
{
    ios::sync_with_stdio(false);
    int t,k,idx;
    t = 1;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&arr[i]);
            v.pb(arr[i]);
        }
        sort(all(v));
        k = 0;
        for(int i=1;i<n;i++)
        {
            if(isSorted())
                    break;            
            else
            {
                for(idx=i;idx<=n;idx++)
                    if(arr[idx] == v[i-1])
                        break;
                if(idx == i)
                    continue;
                x[k] = i;
                y[k++] = idx;
                reverse(arr+i,arr+idx+1);
            }
  
        }
        cout<<k<<endl;
        for(int i=0;i<k;i++)
            cout<<x[i]<<" "<<y[i]<<endl;

    }
    return 0; 
}

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
int arr[110],stock[110];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,cnt,height,pick,neg;
    cin>>t;
    while(t--)
    {
        memset(stock,0,sizeof(stock));
        cin>>n;
        rep(i,n)
            cin>>arr[i];
        sort(arr,arr+n);
        int pick = 0;
        int neg=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] >= 0)
            {
                height = 1;
                pick =  arr[i];
                arr[i]=-1;
                for(int j=i;j < n;j++)
                {
                    
                    if(height <= arr[j] and arr[j] >= 0 and pick <= arr[j] and arr[j]!=0)
                    {
                        pick = arr[j];
                        height++;
                        arr[j] = neg;
                        neg--;
                    }
                }
                stock[height]++;	
            }
        }
    }
    return 0;
}

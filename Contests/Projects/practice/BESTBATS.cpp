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
int arr[20];
int main()
{
    ios::sync_with_stdio(false);
    int t,k,sum;
    cin>>t;
    while(t--)
    {
        sum = 0;
        rep(i,11) cin>>arr[i];
        sort(arr,arr+11);
        cin>>k;
        for(int i=10;i>=10-k+1;i--)
            sum += arr[i];
        int cnt = 0,temp;
        for(int i=0;i<(1<<11);i++){
            temp = 0;
            if(__builtin_popcount(i) == k)
            for(int j=0;j<11;j++)
                if(i & (1<<j))
                    temp += arr[j];
        
            if(temp == sum)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0; 
}


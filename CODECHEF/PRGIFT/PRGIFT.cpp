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

#define MAX 110
#define MOD 1000000007
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,K,var,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n>>K;
        rep(i,n)    cin>>arr[i];
        
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                cnt=0;
                for(int k=i;k<=j;k++)
                    if(arr[k]%2 == 0)
                        cnt++;
               
                if(cnt == K){
                    cout<<"YES"<<endl;
                    goto down;
                }
            }
        
        cout<<"NO"<<endl;
        down:;
    }
    return 0; 
}

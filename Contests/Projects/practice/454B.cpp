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
int a[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,i,l,r;
    cin>>n;
    for( i=0;i<n;i++)
        cin>>a[i];
    /*if(n == 2){
        i =0;
        if(a[i]<=a[i+1])cout<<0<<endl;
        else
            cout<<1<<endl;
        return 0;
    }*/
    l  = 1 ;  r = 0; 
    for( i=1;i<=n-1; ){
         while(i<n and a[i-1]<=a[i]){
             i++;
         }
         if(i<n and a[i] <= a[0]){
             i++;
             l = i;r = i;
         }
        // cout<<i<<endl;
         while(i<n and a[i] <= a[0] and a[i-1]<=a[i]){
             i++;
             r++;
         }
         break;
     }
    //cout<<i<<" " << l << " " << r << endl;
     if(i<n)cout<<-1<<endl;
     else
         cout<<r-l+1<<endl;


     /*<F5>if(i == n){
         cout<<0<<endl;return 0;}

     if(i<n-1){
         cout<<-1<<endl;
     }
     else{
         cout<<r-l+1<<endl;
     }*/
    return 0; 
}

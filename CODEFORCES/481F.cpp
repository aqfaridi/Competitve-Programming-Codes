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

#define MAX 2000010
#define MOD 1000000007
LL arr[MAX],sum[MAX],arr2[MAX],sum2[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
   

    if(2*k >= n){
        cout<<sum[n]<<endl;
        return 0;
    }

    LL temp = 0 , maxx = 0 , pos = 1;
    for(int i=1;i<=n;i++){
        if(i+k-1 > n)  break;

        temp = sum[i+(k-1)] - sum[i-1];
        if(temp > maxx){
            maxx = temp;
            pos = i;
        }
    }
 
    int x = 1;
    for(int i=1;i<pos;i++)
        arr2[x++] = arr[i];
    for(int i=pos+k;i<=n;i++)
        arr2[x++] = arr[i]; 
    
    int range = x - 1;

    for(int i = 1;i<=range;i++)
        sum2[i] = sum2[i-1] + arr2[i];


    LL temp2 = 0 , maxx2 = 0 , pos2 = 1;
    for(int i=1;i<=range;i++){
        if(i+k-1 > range)  break;

        temp2 = sum2[i+(k-1)] - sum2[i-1];
        if(temp2 > maxx2){
            maxx2 = temp2;
            pos2 = i;
        }
    }

    LL ans = maxx + maxx2;
    cout << ans << endl;


    return 0; 
}


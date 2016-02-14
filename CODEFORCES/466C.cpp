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

#define MAX 500010
#define MOD 1000000007
int arr[MAX],mark[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    LL sum = 0,S = 0;
    cin>>n;
    rep(i,n){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum % 3 != 0){
        cout<<0<<endl;
        return 0;
    }

    sum /= 3;
    for(int i=n-1;i>=0;i--){
        S += arr[i];
        if(S == sum)
            mark[i] = 1;
    }

    for(int i=n-2;i>=0;i--)
        mark[i] += mark[i+1];

    S = 0;
    LL ways = 0;
    for(int i=0;i<n;i++)
    {
       S += arr[i];
       if(S == sum)
           ways += (mark[i+2]);
    }

    cout<<ways<<endl;


    return 0; 
}


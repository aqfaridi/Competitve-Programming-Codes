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

#define MAX 1000100
#define MOD 1000000007
int a[MAX];
LL arr[MAX];
void sieve()
{
    a[0] = a[1] = 1;
    for(int i= 2; i*i <= MAX ; i++)
    {
        if(!a[i])
        {
            for(int j= i*i; j < MAX ; j+= i)
                a[j] = 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    sieve();
    int t,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //if(arr[i] == 1){ cout<<"NO"<<endl;continue;}
        LL sq = sqrt(arr[i]);
        if(sq*sq == arr[i]){
            if(a[sq] == 0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";
    }
    return 0; 
}

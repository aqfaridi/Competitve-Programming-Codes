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
set<int> s;
map<int,int> m;
int arr[MAX],mark[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n,a,b,A,B;
    cin>>n>>a>>b;
    rep(i,n){
        cin>>arr[i];
        m[arr[i]] = i;
        s.insert(arr[i]);
    }

    set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        if(!mark[i]){
            A = a - arr[i];
            it = s.find(A);            
            if(it != s.end() && !mark[m[(*it)]]){
                mark[i] = 1;
                mark[m[(*it)]] = 1;
            }
        }

    }

    for(int i=0;i<n;i++)
    {
        if(!mark[i]){
            B = b - arr[i];
            it = s.find(B);
            if(it != s.end() && !mark[m[(*it)]]){
                mark[i] = 2;
                mark[m[(*it)]] = 2;
            }
        }
    }

    bool f=false;
    for(int i=0;i<n;i++)
        if(!mark[i]){
            f = true;
            break;
        }
    if(f){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<mark[i]-1<<" ";
    cout<<endl;

    return 0; 
}


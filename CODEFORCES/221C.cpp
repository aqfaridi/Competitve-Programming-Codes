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
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n)    cin>>arr[i];
    int i,idx1 = -1,idx2 = -1;
    for(i=1;i<n;i++)
        if(arr[i] < arr[i-1]){ 
            idx1 = i-1;
            break;
        }


    if(idx1 == -1){
        cout<<"YES"<<endl;
        return 0;
    }

    idx2 = idx1+1;
    for(int i=idx1+2;i<n;i++){
        if(arr[i] < arr[i-1]){
            idx2 = i;
            break;
        }
    }
    //cout<<idx1<<" "<<idx2<<endl;
    swap(arr[idx1],arr[idx2]);
    int res = -1;
    for(i=1;i<n;i++)
        if(arr[i] < arr[i-1]){ 
            res = i-1;
            break;
        }

    if(res == -1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0; 
}

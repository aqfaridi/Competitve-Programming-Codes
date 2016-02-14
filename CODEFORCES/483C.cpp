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
int arr[MAX],n,k;
/*void analyse()
{
    for(int i=0;i<n;i++)
        arr[i] = i+1;

    set<int> s;
    do{
        s.clear();
        for(int i=1;i<n;i++)
            s.insert(abs(arr[i] - arr[i-1]));
        
        if(s.size() == k){
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }while(next_permutation(arr,arr+n));
}*/
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    //analyse();
    int end = n;
    int start = 1;
    for(int i=0;i<k;i++)
        if((i&1))
            arr[i] = end--;
        else
            arr[i] = start++;

    if((k&1))
        for(int i=k;i<n;i++)
            arr[i] = start++;
    else
        for(int i=k;i<n;i++)
            arr[i] = end--;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0; 
}


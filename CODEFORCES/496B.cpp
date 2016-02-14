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
typedef pair< int, pii > tri;

#define pb push_back
#define mp make_pair
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int arr[MAX],temp[MAX],rev[MAX],maxx[MAX];
int n;
void compare(int a[],int b[]){
    bool f = false;
    for(int i=0;i<n;i++){
        if(a[i] == b[i])    continue;
        if(a[i] < b[i]){
            f = true;
            break;
        }
        else
            break;
    }

    if(f){
        for(int i=0;i<n;i++)
            b[i] = a[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        arr[i] = str[i]-'0';
        maxx[i] = arr[i];
    }
    
    
    int t = 12;

    while(t--){
        for(int i=0;i<n;i++)
            temp[i] = (arr[i] + 1)%10;
        
        for(int i=0;i<n;i++)
            rev[i] = arr[i];

        for(int j=0;j<n;j++){
            rotate(rev,rev+1,rev+n);
            compare(rev,maxx);
        }
        
        compare(temp,maxx);   
        compare(rev,maxx);

        for(int i=0;i<n;i++)
            arr[i] = temp[i];
    }

    for(int i=0;i<n;i++)
        cout<<maxx[i];

    return 0; 
}


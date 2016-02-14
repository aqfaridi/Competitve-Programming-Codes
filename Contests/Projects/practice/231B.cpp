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
int arr[110];
int main()
{
    ios::sync_with_stdio(false);
    int n,d,l;
    cin>>n>>d>>l;
    int x,n2 = n/2,n21 = (n+1)/2,fx=-1,fy=-1;
    for(int y=n2;y<=(n2*l);y++)
    {
        x = (d + y);
        if(x <= n21*l && x >= n21){
            fx = x;
            fy = y;
            break;
        }
    }

    if(fx == -1 || fy == -1){    cout<<-1<<endl;return 0; }

    int sumx=0,sumy=0;
    for(int i=1;i<=n;i++)
    {
        if((i&1)){
            arr[i] = fx/n21;sumx += arr[i]; }
        else{
            arr[i] = fy/n2;sumy += arr[i]; }
    }

    if(fy%n2 != 0){
        for(int i=1;i<=n && sumy < fy;i++)
            if(i%2 == 0)
            {
                while(arr[i] < l && sumy < fy)
                {
                    arr[i]++;
                    sumy++;
                }
            }
    }

    if(fx%n21 != 0){
        for(int i=1;i<=n && sumx < fx;i++)
            if(i%2 == 1)
            {
                while(arr[i] < l && sumx < fx)
                {
                    arr[i]++;
                    sumx++;
                }
            }
    }

    for(int i=1;i<=n;i++)   cout<<arr[i]<<" ";
    cout<<endl;

    return 0; 
}

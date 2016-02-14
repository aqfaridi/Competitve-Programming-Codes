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

#define N 1000000007
LL a[8],b[8];
int main()
{
    ios::sync_with_stdio(false);
    LL x,y,n;
    cin>>x>>y;
    cin>>n;
    if(x >=0 ) 
    {
        a[0] = x%N;
        b[0] = x;

    }
    else
    {
        a[0] = x%N + N;
        b[0] = x;
    }

    if(y >= 0)
    {
        a[1] = y%N;
        b[1] = y;
            
    }
    else
    {
        a[1] = y%N + N;
        b[1] = y;
    }

    for(int i=2;i<8;i++)
    {
        b[i] = b[i-1]-b[i-2];
        if(b[i] >=0)
        {
            a[i] = b[i] % N;
        }
        else
            a[i] = b[i] % N + N;
    }
    if( n<=2)
    {
        cout<<a[n-1];
    }
    else
        cout<<a[(n-2)%6 + 2 - 1];
    return 0; 
}

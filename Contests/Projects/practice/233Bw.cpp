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
int sumdig(int n)
{
    int sm = 0;
    while(n){
        sm += n%10;
        n /= 10;
    }
    return sm;
}
int main()
{
    ios::sync_with_stdio(false);
    LL n,x;
    bool b = true;
    cin>>n;
    for(int i=1;i<=162;i++)
    {
        LL vl = sqrt(i*i+4*n);
        if(vl*vl == (i*i+4*n))
        {
            if((vl-i)%2 == 0){
                x = (vl-i)/2 ;
                if(sumdig(x) == i)
                {
                    cout<<x<<endl;
                    b = false;
                    break;
                }
            }
        }
    }
    if(b)
        cout<<-1<<endl;
    return 0; 
}

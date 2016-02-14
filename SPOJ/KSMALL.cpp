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

#define MAX 5000000
#define MOD 1000000007
unsigned array[MAX];
void randomize(unsigned a,unsigned b,unsigned mod)
{
    for( int i=0 ; i<5000000 ; i++ )
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        array[i] = ((a << 16) + b) % mod;
        if(i<100)
            print(array[i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,a,b,mod,K;
    t = 1;
    while(t--)
    {
        cin>>a>>b>>mod>>K;
        randomize(a,b,mod);
        partial_sort(array,array+K,array+MAX);
    //    for(int i=0;i<K;i++)
      //      print(array[i]);
        pn();
        cout<<array[K-1]<<endl;
    }
    return 0; 
}

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

#define MAX 1000010
#define MOD 1000000007
int sieve[MAX];
int cnt[MAX];
void make_sieve()
{
    sieve[0] = sieve[1] = 1;
    for(int i=0;i*i<MAX;i++)
    {
        if(!sieve[i])
            for(int j=i*i;j<MAX;j+=i)
                sieve[j] = 1;
    }

    for(int i=1;i<MAX;i++)
        if(sieve[i] == 0)
            cnt[i] = cnt[i-1] + 1;
        else
            cnt[i] = cnt[i-1];

    for(int i=1;i<=20;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
}
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int a,b,k,i;
    cin>>a>>b>>k;
    for(i=a;i<=b;i++)
    {
        if(cnt[i]-cnt[a-1] > k)
            break;
    }
    cout<<i<<endl;
    cout<<i-a<<endl;
    return 0; 
}

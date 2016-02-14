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
int primes[MAX];
void make_sieve()
{
    sieve[0] = sieve[1] = 1;
    for(int i=2;i*i<MAX;i++)        
    {
        if(!sieve[i])
            for(int j=i*i;j<MAX;j+=i)
                sieve[j] = 1;
    }
    
    int k = 0;
    for(int i=2;i<MAX;i++)
        if(!sieve[i])
            primes[k++] = i;
}
int arr[10020];
map<int,int> m;
bool prime_factorize(int n,int f)
{
    int cnt;
    for(int i=0;1LL*primes[i]*primes[i] <= n;i++)
    {
        if(n%primes[i] == 0){
            cnt = 0;
            while(n%primes[i] == 0){
                cnt++;
                n/=primes[i];
            }
            if(primes[i] != 2)
            {
                if(f && m[primes[i]] != cnt)    return false;
                m[primes[i]] = cnt; 
            }
        }
            
    }
    if(n>1){
        if(f && m[n] != 1)    return false;
        m[n] = 1;
    }
    
    return true;
}
int main()
{
    make_sieve();

  ios::sync_with_stdio(false);
  int t,n;
  bool b;
  cin>>t;
  while(t--)
  {
    m.clear();
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    prime_factorize(arr[0],0);
    int i;
    for(i=1;i<n;i++)
    {
       b  = prime_factorize(arr[i],1);
       if(!b)   break;
    }
    
    if(b)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
  }



    return 0; 
}
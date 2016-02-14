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
int primes[MAX],k;
vector<bool> sseive(MAX);
#define Lim 1001
unsigned flag[MAX>>6];
#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
void sieve()
{
   
    for(int i=3;i<Lim;i+=2)
    {
        if(!ifc(i))//testing
        {
            for(int j=i*i,k=i<<1; j<MAX;j+=k)//only odd numbers
            {
                isc(j);//setting
            }
        }
    }
    k = 0;
    primes[k++] = 2;
    primes[k++] = 3;
    primes[k++] = 4;
    for(int i=5;i<MAX;i+=2)//only odd flagging is done
    {
        if(!ifc(i))
            primes[k++] = i;
    }
    
}


int main()
{
    sieve();
    int t,L,R;
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&L,&R);
        //cin>>L>>R;
        printf("%d\n",R-L+1 - (upper_bound(primes,primes+k,R) - lower_bound(primes,primes+k,L)));
        //cout<< (R-L+1) - (sieve[R]-sieve[L-1]) <<endl;
        
    }
    return 0;
}
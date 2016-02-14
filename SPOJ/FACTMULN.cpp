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

#define MAX 32000
#define MOD 1000000007
#define LIM 179
int sieve[MAX],primes[MAX];
void make_sieve()
{
    sieve[0] = sieve[1] = 1;
    for(int i=2;i <= LIM;i++)
    {
        if(!sieve[i])
            for(int j=i*i;j <= MAX;j+=i)
                sieve[j] = 1;
    }
    int k = 0;
    for(int i=2;i<MAX;i++)
        if(!sieve[i])
            primes[k++] = i;

}
LL binary(int p,int n)
{
    LL checkpoints,rem_elements,contr,others,ans,pwr;
    pwr = p;
    ans = 0;
    while(pwr <= n)
    {
        checkpoints = n/pwr;
        rem_elements = n%pwr;            
        contr = pwr * (checkpoints*(checkpoints-1)/2);
        others = checkpoints*(rem_elements+1);
        ans += (contr+others);
        pwr *= p;
    }
    return ans;
}
int x[100010];
int pwr[100010];
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    LL t,n,sqr,k,N,chk1,chk2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        N = n;        
        k = 0;
        for(int i=0;primes[i]*primes[i] <= n;i++)
        {
            if(n%primes[i] ==0)
            {
                x[k] = primes[i];
                pwr[k] = 0;
                while(n%primes[i] == 0)
                {
                    pwr[k]++;
                    n/=primes[i];
                }
                k++;
            }
        }
        if(n>1)
        {
            x[k] = n;
            pwr[k] = 1;
            k++;
        }
        //we got x and pwr
        int low,high,mid,maxx = -1;
        for(int i=0;i<k;i++)
        {
            //trace2(x[i],pwr[i]);
            low=0,high=N;
            while(low <= high)
            {
                mid = (low+high)/2;
                chk1 = binary(x[i],mid);
                chk2 = binary(x[i],mid-1);
                //trace2(chk1,chk2);
                if(chk1 > pwr[i] && chk2 >= pwr[i])
                    high = mid - 1; 
                else if (chk1 < pwr[i] && chk2 < pwr[i])
                    low = mid + 1;
                else 
                    break;
            }
            //cout<<mid<<endl;
            maxx = max(maxx,mid);
        }
        
        cout<<maxx<<endl;
    }
    return 0; 
}

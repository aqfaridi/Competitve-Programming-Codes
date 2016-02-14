#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MOD 1000000007    
namespace sieve
{
    #define MAX 1000010
    #define LIM 1000
    #define PRM 78500
    unsigned flag[MAX >> 6];
    LL primes[PRM];
    #define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
    #define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
    void make_sieve()
    {
        unsigned i,j,k;
        isc(1);
        for(i=3;i<=LIM;i+=2)
        {
            if(!ifc(i))
                for(j=i*i,k=(i<<1);j<MAX;j+=k)
                    isc(j);
        }
        primes[0] = 2;
        for(i=3,k=1;i<MAX;i+=2)
            if(!ifc(i))
                primes[k++] = i;
       /* 
        for(int i=0;i<100;i++)
            cout<<primes[i]<<" ";
        cout<<k<<endl;
        */
    }
}
using namespace sieve;
int square[MAX];
void precompute()
{
    LL num,cnt;
    bool flag;
    for(LL x=1;x<100001;x++)
    {
        flag = true;
        num = x*x;
        for(int i=0;primes[i]*primes[i] <= num;i++)
        {
            if(num%primes[i] == 0)
            {
               cnt = 0;
               while(num%primes[i] == 0)
               {  cnt++; num /= primes[i]; }
               if((primes[i]%4==3) && (cnt&1))
               {
                    flag = false;
                    break;
               }
            }
        }
        if(num > 1)
            if(num % 4 == 3)//already odd power i.e = 1
                flag = false;
        if(flag)
            square[x] = 1;        
    }
}

int main()
{
    make_sieve();
    precompute();
    ios::sync_with_stdio(false);
    int t;
    bool flag;
    LL num,n,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n >= 100001)
        { 
            flag = true;
            num = n*n;
            for(int i=0;primes[i]*primes[i] <= num;i++)
            {
                if(num%primes[i] == 0)
                {
                   cnt = 0;
                   while(num%primes[i] == 0)
                   {  cnt++; num /= primes[i]; }
                   if((primes[i]%4==3) && (cnt&1))
                   {
                        flag = false;
                        break;
                   }
                }
            }
            if(num > 1)
                if(num % 4 == 3)//already odd power i.e = 1
                    flag = false;
            if(flag)
                square[n] = 1;        
        }


        if(square[n])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

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
#define MAX 10000010
int primes[664580];
unsigned flag[MAX >> 6];
#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
void sieve()
{
    unsigned i,j,k;
    for(i=3;i<=3163;i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i,k=(i<<1);j<=MAX;j+=k)
                isc(j);
        }
    }
    k=0;
    primes[k++] = 2;
    for(i=3;i<=MAX;i+=2)
    {
        if(!ifc(i))
            primes[k++] = i;
    }
}
bool psycho[MAX];
void factorize()
{
    int odd,even,n,cnt;
    for(int nn=2;nn<=MAX;nn++)
    {
        odd = even = 0;
        n = nn;
        for(int i=0;primes[i]*primes[i] <= n;i++)
        {
            if(n%primes[i] == 0)
            {
                cnt = 0;
                while(n%primes[i] == 0)
                {
                    cnt++;
                    n/=primes[i];
                }
                if(cnt&1)   odd++;
                else    even++;
            }
        } 
        if(n>1)
            odd++;

        if(even > odd)
            psycho[nn] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
   // sieve();
   // factorize();
    /*
    for(int i=0;i<100;i++)
        cout<<primes[i]<<" ";
    cout<<endl;
    */
    int t,n,cnt,odd,even;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        odd = even = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt=0;
                while(n%i==0)
                { cnt++; n/=i; }

                if(cnt&1) odd++;
                else even++;
            }
        }
        if(n>1)
            odd++;

        if(even>odd)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;
}



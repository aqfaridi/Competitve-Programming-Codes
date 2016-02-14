#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000010
#define LIM 1000
#define PRM 78500
typedef long long LL;
int sieve[MAX],segment[MAX];
LL primes[PRM];
void make_sieve()
{
    int i,j,k;
    sieve[0] = sieve[1] = 1;
    for(i=2;i<=LIM;i++)
    {
        if(!sieve[i])
            for(j=i*i;j<MAX;j+=i)
                sieve[j] = 1;
    }
    primes[0] = 2;
    for(i=3,k=1;i<MAX;i+=2)
        if(!sieve[i])
            primes[k++] = i;
    /** 
    for(int i=0;i<100;i++)
        cout<<primes[i]<<" ";
    cout<<k<<endl;
    **/
}
LL segmented_sieve(LL a,LL b)
{
    memset(segment,0,sizeof(segment));  
    int i,j,cnt=0;
    for(i=0;(primes[i]*primes[i])<=b;i++)
    {
        j = (-a) % primes[i];
        if(j==0)
            j += (primes[i]+a);
        else 
            j += (2*primes[i]+ a);               
        cout<<primes[i]<<" "<<j<<endl;
        for(;j<=b;j+=primes[i])
                segment[(j-a)] = 1;
        for(int i=0;i<=99;i++)
            cout<<segment[i]<<" ";
        cout<<endl;
    }

    for(i=0;i<=(b-a);i++)
        if(!segment[i])
        {
            cout<<a+i<<endl;
            cnt++;
        }
    return cnt;
}

long long PS[MAX];
void make_ps()
{
    for(long long i=0;i<MAX;i++)
        PS[i] = i*i;
}
int main()
{
    make_sieve();
    make_ps();
    int t,cnt,pro,special,idx1=0,idx2=0;
    LL l,r,n;
    scanf("%d",&t);
    while(t--)
    {
        special = 0;
        scanf("%lld %lld",&l,&r);
        idx1 = lower_bound(PS,PS+MAX,l) - PS;
        idx2 = upper_bound(PS,PS+MAX,r) - PS;
        for(long long x=idx1;x<idx2;x++)
        {
            n = PS[x];
            pro = 1;
            for(int i=0;(primes[i]*primes[i])<=n;i++)
            {
                if(n%primes[i]==0)
                {
                    cnt = 0;
                    while(n%primes[i]==0)
                    {
                        cnt++;
                        n /= primes[i];
                    }
                    pro *= (cnt+1);
                }
            }
            if(n>1)
                pro *= 2;
            if(!sieve[pro])
                special++;
        }
        cout<<special<<endl;
        special += segmented_sieve(l,r);
        printf("%d\n",special);
    }
    return 0;
}

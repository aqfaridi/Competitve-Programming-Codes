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
namespace sieve
{
    #define MAX 10000010
    #define LIM 3163
    #define PRM 78500
    typedef long long LL;
    unsigned flag[MAX >> 6];
    unsigned segment[MAX >> 6];
    LL primes[1000010];
    #define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
    #define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
    #define seg_ifc(n) (segment[n>>6] & (1<<((n>>1)&31)))
    #define seg_isc(n) (segment[n>>6] |= (1<<((n>>1)&31)))
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
int arr[100010];
int main()
{
    make_sieve();
    int n,k;
    cin>>n>>k;
    if(n==k)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<"2 ";
    for(int i=2;i<=k+1;i++)
        cout<<i*i<<" ";
    int ptr=1;
    for(int i=k+2;i<=n;i++)
    {
        if(!(i&1))
            cout<<primes[ptr++]<<" ";
        else
        {
            if(!ifc(i) && i==primes[ptr])
            {
                ptr+=1;
                cout<<primes[ptr]<<" ";
                ptr+=1;
            }
            else
                cout<<primes[ptr++]<<" ";
        }
    }

    return 0;
}

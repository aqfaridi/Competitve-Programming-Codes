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

#define MAX 100010
unsigned flag[MAX>>6];
#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
int primes[100000] , nodiv[MAX];
void sieve()
{
    unsigned i,j,k;
    for(i=3;i<=317;i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i,k=(i<<1);j<=MAX;j+=k)
            {
                isc(j);
            }
        }
    }
    k=0;
    primes[k++]=2;
    for(i=3;i<=MAX;i+=2)
        if(!ifc(i))
            primes[k++] = i;
}
void factorize()
{
    int cnt,pro,n;
    nodiv[0] = 0;
    nodiv[1] = 1;
    for(int nn=2;nn<=MAX;nn++)
    {    
        pro = 1;
        n = nn;
        for(int i=0;primes[i]*primes[i]<=n;i++)
        {
            if(!(n%primes[i]))
            {
                cnt = 0;
                while(!(n%primes[i]))
                {
                    n/=primes[i];
                    cnt++;
                }
                pro *= (2*cnt+1);
            }               
        }
        if(n>1)
        {
            pro *= (3);
        }

        
        nodiv[nn] = pro;
    }
}
vector<long long> v[MAX];
void precalc()
{
    for(long long nn=0;nn<=MAX;nn++)
    {
        //v[nodiv[nn].first].push_back(nn);
        v[nodiv[nn]].push_back(nn * nn);//already sorted acc. to loop            
    }
}
int main()
{
    sieve();
    factorize();
    precalc();
    //for(int i=0;i<100;i++)
     //   cout<<primes[i]<<" ";
    //cout<<endl;
    int t;
    long long cnt,k,low,high;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld %lld %lld",&k,&low,&high);
 //     for(int i=0;i<=235;i++) 
   //       cout<<nodiv[i]<<" ";
     // cout<<endl;
/*
       for(int i=5;i<=5;i++)
       {
            for(int j=0;j<v[i].size();j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
       }
*/      
       cnt =  (upper_bound(v[k].begin(),v[k].end(),high) - lower_bound(v[k].begin(),v[k].end(),low));        
       //vector<vector<int> >::iterator it; 
       //cout<< lower_bound(v[k].begin(),v[k].end(),high);
       printf("%lld\n",cnt);
    }
    return 0;
}



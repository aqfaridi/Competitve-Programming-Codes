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
#define MAX 1000010
unsigned flag[MAX>>6];
#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
int primes[1000000];
void sieve()
{
    unsigned i,j,k;
    for(i=3;i<=1000;i+=2)
    {
        if(!ifc(i))
        {
            for(k=(i<<1),j=i*i;j<=MAX;j+=k)
                isc(j);
        }
    }
    primes[0]=2;
    k=1;
    for(int i=3;i<=MAX;i+=2)
        if(!ifc(i))
            primes[k++] = i;
}
int divisors(int a,int b,int n)
{
    int cnt,i,Num;
    int pro,send=0;
    for(int num=a ; num<=b ; num++)
    {
       Num = num;
       pro = 1;
       for(i=0;primes[i]<=sqrt(Num);i++)
       {
           if(!(Num%primes[i]))
           {
                cnt = 0;
                while(!(Num%primes[i]))
                {
                    Num /= primes[i];
                    cnt++;
                }
                pro *= (cnt+1);
           }
           //cout<<pro<<endl;
       }
       if(Num > 1)
           pro *= (2);
       //cout<<num<<" "<<pro<<endl;
       if(pro == n)
           send++;
    }
    return send;
}
int main()
{
    sieve();
    //for(int i=0;i<168;i++)
      //  cout<<primes[i]<<" ";
    ios::sync_with_stdio(false);
    int a,b,n;
    cin>>a>>b>>n; 
    cout<<divisors(a,b,n)<<endl;
    return 0;
}



#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef unsigned long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
LL nCr[65][65];
LL make_nCr(LL n, LL r)
{
    if(r==0 || n==r)
        return 1;
    if(nCr[n][r] > 0)
        return nCr[n][r];
    return nCr[n][r] = make_nCr(n-1,r-1) + make_nCr(n-1,r);
}
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
LL bitprimes(LL n)
{
    int already = 0;
    LL total = 0;
    for(int i=__lg(n);n>0;i=__lg(n))
    {           
        for(int j=0;j<=18;j++)
        {
           //if(primes[j]-already > i)
             //  break;
           if(primes[j]-already >= 0 && primes[j]-already <= i)
                total += make_nCr(i,primes[j]-already); 
        }
        already++;
        n ^= (1LL << i);//reset ith bit
    }

    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        b += 1;
        cout<<bitprimes(b) - bitprimes(a)<<endl;        
    }
    return 0;
}

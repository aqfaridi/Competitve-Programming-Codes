/**
 * SPOJ Problem Set (classical)
 * 9494. Just Add It
 * Problem code: ZSUM
 *
 * For two given integers n and k find (Zn+Zn-1-2Zn-2)mod 10000007 ,
 * where Zn=Sn+Pn and Sn=1k+2k+3k+...+nk and Pn=11+22+33+..+nn.
 * Input
 *
 * There are several test cases [ .10000 ].In each case two space
 * separated positive integers n and k are given.
 * For last test case n and k are given  as 0  0 ,which is  not to be
 * processed.
 * 1<n<200000000 , 0<k<1000000.
 * Output
 *
 * For each case print the asked value in separate line.
 * Example
 *
 * Input:
 * 10 3
 * 9 31
 * 83 17
 * 5 2
 * 0 0 
 *
 * Output:
 *
 * 4835897
 * 2118762
 * 2285275
 * 3694
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 10000007
using namespace std;
long long int power(long long int  a,long long int n)////dont make pow with 2 arguments as it is in cmath already
{
    long long int result=1;
    while(n>0)  //until expo > 0
    {
       
        if(n&1) //odd n
           result=(result*a)%MOD;
        
        a=(a*a)%MOD;
        n/=2;
    }
    return result%MOD;

}
int main()
{
    int n,k;
    
    long long int a,b,c,d,zsum;
    while(1)
    {
        zsum=0;
        scanf("%d %d",&n,&k);
        if(n==0 && k==0)
            break;
        a=power((n-1),k);
        b=power((n-1),(n-1));
        c=power(n,k);
        d=power(n,n);
        zsum= (((((2*(a+b))%MOD)+c)%MOD)+d)%MOD;
        printf("%lld\n",zsum);
    }
    return 0;
}


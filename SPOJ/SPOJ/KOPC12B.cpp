/**
 *SPOJ Problem Set (classical)
 10515. K12-Combinations
 Problem code: KOPC12B

  
 (nC1)^2+2*(nC2)^2+3*(nC3)^2+4*(nC4)^2+............+n*(nCn)^2.   % MOD
 where MOD=10^9+7;
 Input Format:
 The first line of input file contains T which denotes number of testcases.Each of the following line contains an integer n. T<=1000 && n<=10^6.
 Output Format:
 The output must contain T lines each line corresponding to a testcase.
 Input
 2
 1
 2
Output:
1

Given n  find the value of ((nC1)2+2*(nC2)2+3*(nC3)2+4*(nC4)2+............+n*(nCn)2)% MOD

where MOD=10^9+7.

Note: nCr is the number of ways of choosing r items from n items.
Input

The first line of input file contains T which denotes number of testcases.Each of the following line contains an integer n. T<=1000 && n<=10^6.
Output

The output must contain T lines each line corresponding to a testcase.
Example

Input:

2
1
2


Output:

1
6
*/
#include <iostream>
#define MOD 1000000007
#define MAX 1000010
#include <cstdio>
using namespace std;
long long int arr[2*MAX+1];
long long int expo(long long a,long long n,long long m)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return result%MOD;
}
int main()
{
    long long  t,n;
    arr[1]=1,arr[0]=1;
    long long factNr,factDr;
    for(int i=2;i<2*MAX;i++)
        arr[i]=(arr[i-1]*i)%MOD;
    scanf("%lld",&t);
    while(t--)
    {

        scanf("%lld",&n);
        factNr=arr[2*n-1];
        factDr=arr[n-1];
        n= (((n * factNr)%MOD * expo(factDr,MOD-2,MOD))%MOD * expo((n*factDr)%MOD,MOD-2,MOD) )%MOD ;
        printf("%lld\n",n);
    }
    return 0;
}




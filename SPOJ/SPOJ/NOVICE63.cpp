/**
 * SPOJ Problem Set (classical)
 * 9103. Special Numbers
 * Problem code: NOVICE63
 *
 * Ted thinks that integers having equal number of 1's and 0's in
 * their binary representation are special. Therefore, he wants to
 * know how many such integers are present.
 *
 * Note: For this problem, the binary representation of an integer(>0)
 * is considered from the least significant bit to the last set bit.
 * Which means, 5 has a binary representation of 101, 3 has a binary
 * representation of 11 etc. As such, one example of a special number
 * is 9 which has a binary representation, 1001.
 * Input
 *
 * First line contains an integer T(atmost 100) denoting the total
 * number of test cases. Each test case contains a single integer N(2
 * <= N <= 2^60). N is always a power of 2.
 * Output
 *
 * A single integer denoting the total number of such special numbers
 * in the range 1 to N (inclusive).
 * Example
 *
 * Input:
 * 3
 * 8
 * 16
 * 32
 *
 * Output:
 * 1
 * 4
 * 4
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 70
using namespace std;
long long nCrdp[MAX];
long long nCr(long long n,long long r)
{

    nCrdp[0]=1;nCrdp[1]=n;
    for(int i=2;i<=r;i++)
       nCrdp[i]= (nCrdp[i-1] * (n-(i-1))) / i;//int * int

    return nCrdp[r];
}

int main()
{
    int t,nod=0;
    long long n;
    long long dp[MAX];
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld",&n);
       nod = log2(n) + 1;
       dp[0]=0;dp[1]=1;dp[2]=1;
       for(int i=3;i<=nod;i++)
       {
           if((i & 1))
               dp[i] = dp[i-1];
           else
               dp[i] = dp[i-1] +  nCr(i-1,i/2);
       }
      // cout<<nCr(9,4)<<endl;
     //  for(int i=0;i<=4;i++)
      //     cout<<nCrdp[i]<<" ";
    //   for(int i=0;i<=nod;i++)
      //     cout<<dp[i]<<" ";
     //  cout<<endl;
        printf("%lld\n",dp[nod-1]);

    }

    return 0;

}

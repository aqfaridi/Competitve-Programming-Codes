/**
 * SPOJ Problem Set (classical)
 * 5979. Yet Another Permutations Problem
 * Problem code: YAPP
 *
 * How many permutations of the first N numbers exist such that the
 * maximum element between the indices [i..j] is either present at
 * index i, or at index j ?
 *
 *
 * Input
 *
 * The first line contains the number of test cases T. Each of the
 * next T lines contains an integer N
 *
 *
 * Output
 *
 * Output T lines containing the required answer for the corresponding
 * test case. Since the answers can get really big, output the result
 * modulo 1000000007.
 *
 * Example
 *
 *
 * Sample Input :
 * 1
 * 2
 *
 * Sample Output :
 * 2
 *
 *  
 *
 *  Constraints
 *
 *   
 *
 *   1 <= T <=10000
 *
 *   1 <= N <= 1000000000
 *   */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long expo(long long a,long long n)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result = (result*a) % MOD;
        a = (a*a) % MOD;
        n >>= 1;
    }
    return result % MOD;
}
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",expo(2,n-1));
    }
    return 0;
}


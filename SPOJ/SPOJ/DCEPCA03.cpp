/**
 * SPOJ Problem Set (classical)
 * 12914. Totient Extreme
 * Problem code: DCEPCA03
 *
 * Given the value of N, you will have to find the value of H. The
 * meaning of H is given in the following code
 *
 * H=0;
 *
 * For( i=1;i<=n;i++){
 *
 *                 For( j=1;j<=n;j++){
 *
 *                                     H=H+totient(i)*totient(j);
 *
 *                                               }
 *
 *                                               }
 *
 *                                               Totient or phi
 *                                               function, φ(n) is an
 *                                               arithmetic function
 *                                               that counts the
 *                                               number of positive
 *                                               integers less than or
 *                                               equal to n that are
 *                                               relatively prime to
 *                                               n. That is, if n is a
 *                                               positive integer,
 *                                               then φ(n) is the
 *                                               number of integers k
 *                                               in the range 1 ≤ k ≤
 *                                               n for which gcd(n, k)
 *                                               = 1
 *                                               Constraints
 *
 *                                               0 < T <= 50
 *                                               0 < N <= 10^4
 *                                               Input
 *
 *                                               The first line
 *                                               contains T, the
 *                                               number of test cases.
 *                                               It is followed by T
 *                                               lines each containing
 *                                               a number N .
 *                                               Output
 *
 *                                               For each line of
 *                                               input produce one
 *                                               line of output. This
 *                                               line contains the
 *                                               value of H for the
 *                                               corresponding N.
 *                                               Example
 *
 *                                               Input:
 *                                               2
 *
 *                                               3
 *
 *                                               10
 *
 *                                               Output:
 *
 *                                               16
 *
 *                                               1024
 *                                               */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int primes[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
int phival[10001];
void prime_factorize()
{
    double phi;
    int n;
    for(int i=1;i<=10000;i++)
    {
        n=i;
        phi=n;
        for(int j=0;primes[j]*primes[j] <= n; j++)
        {
            if(n % primes[j] == 0)
            {
                phi *= (1-1.0/primes[j]);
                while(n % primes[j] == 0)
                    n /= primes[j];
            }

        }
        if(n>1)
            phi *= (1 - 1.0/n);
      
        phival[i]=int(phi);
        

    }
}
int main()
{
    prime_factorize();
   // for(int i=0;i<100;i++)
   //     cout<<phival[i]<<" ";
 
    int t,n;
    long long int H,sum;
    scanf("%d",&t);
    while(t--)
    {
        H=0;sum=0;
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++)
            sum += phival[i];

        for(int j=1;j<=n;j++)
        {
            H += sum*phival[j];
        }
        printf("%lld\n",H);
    }
        

    return 0;
}


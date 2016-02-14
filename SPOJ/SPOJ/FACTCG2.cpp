/**
 * SPOJ Problem Set (classical)
 * 10818. Medium Factorization
 * Problem code: FACTCG2
 *
 * The task in this problem is to write a number in a multiplication
 * of prime numbers separated by . x.. You need to put the
 *
 * number 1 in this multiplication.
 *
 *
 * Input
 *
 * The input consists of several lines.
 *
 * Each line consists of one integer N (1 <= N <= 10^7) .
 *
 *
 * Output
 *
 * For each line you need to output the factorization separated by .
 * x. and including 1.
 *
 *
 * Sample Input
 *
 * 1
 *
 * 2
 *
 * 4
 *
 * 8
 *
 * Sample Output
 * 1
 * 1 x 2
 * 1 x 2 x 2
 * 1 x 2 x 2 x 2
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 10000000
using namespace std;
//int Prime[(int)ceil(1.25506 * MAX/log(MAX))];
int Prime[MAX];
void sieve()
{
    vector<bool> sieve(MAX,true);

    int k=0;
    for(int i=2;i*i<MAX;i++)
    {
        if(sieve[i])
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                sieve[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++)
        if(sieve[i])
            Prime[k++]=i;

}
int main()
{
    long long int n;
    int z;
    sieve();
    while(scanf("%lld",&n))
    {
        z=0;
        
        //prime factorization
        if(n==1)
            printf("1");
        else
            printf("1 x ");

        for(int d=Prime[z];d*d<=n;z++,d=Prime[z])
        {
        //    d=Prime[z];

            if(n%d==0)
            {
                while(n%d==0)
                {
                    printf("%d ",d);
                    n/=d;
                    if(n>1)
                        printf("x ");
                    
                }
                
           //     printf("%lld^%lld ",d,count);
                        
            }
        }
        if(n>1)
            printf("%lld",n);
        
        printf("\n");
    }
    return 0;
}


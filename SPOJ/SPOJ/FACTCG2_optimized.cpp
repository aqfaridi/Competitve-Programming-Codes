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
#define MAX 10000001
using namespace std;
int a[MAX];
void factorsieve()
{
    for(int i=1;i<MAX;i++)
        a[i]=i;

    for(int i=2;i*i<=MAX;i++)
    {
        if(a[i] == i)
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                if(a[j] == j)
                {

                    a[j]=i;
                   
                }
            }
        }
        
    }
}
int main()
{
    long long int n;
   
    factorsieve();
    while(scanf("%lld",&n) != EOF)
    {
        if(n==1)
        {
           printf("1\n");
           continue;
        }
        printf("1");
                        
        while(n!=1)
        {
           printf(" x %d",a[n]);                                                       n/=a[n];
                                                                                    }
                                
        printf("\n");
        
        
       
    }
    return 0;
}


    /**
 * SPOJ Problem Set (tutorial)
 * 10817. Easy Factorization
 * Problem code: FACTCG
 *
 *
 * The task in this problem is to write a number in a multiplication
 * of prime numbers separated by . x.. You need to put the 
 *
 * number 1 in this multiplication.
 *
 * Input
 *
 * The input consists of several lines.
 *
 * Each line consists of one integer N (1 <= N <= 10^5) .
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
 * Sample Output
 *
 *  
 *
 *  1
 *  1 x 2
 *  1 x 2 x 2
 *  1 x 2 x 2 x 2
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void primefactorize(int n)
{

    for(int d=2;d*d<=n;d++)
    {
        if(n%d == 0)
        {
           
            while(n%d == 0)//n%0 then Floating Point Exception
            {
                printf("%d ",d);
                n/=d;
                if(n>1)
                    printf("x ");
            }
           
        }

    }
    if(n>1)
        printf("%d",n);
    
    printf("\n");
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==1)
            printf("1");
        else 
            printf("1 x ");
        primefactorize(n);
        
    }
    return 0;
}


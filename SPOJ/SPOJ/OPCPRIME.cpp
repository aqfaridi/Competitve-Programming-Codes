/**
 * SPOJ Problem Set (tutorial)
 * 11960. Prime Factorization
 * Problem code: OPCPRIME
 *
 *  
 *
 *  Given a number n (n<=10^12) print all its prime factors in
 *  strictly ascending order.(Note each prime factor should be printed
 *  on a new line)
 *
 *  Warning: Use long long int for taking input.Integer will overflow.
 *  The format specifier for long long int is %lld
 *
 *  Sample Cases :
 *  Input:
 *  60
 *  Output:
 *  2
 *  3
 *  5
 *
 *
 *  Another Example:
 *
 *  Input:
 *  100
 *  Output:
 *  2
 *  5
 *  */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void primefactorize(long long int n)
{

    for(long long int d=2;d*d<=n;d++)
    {
        if(n%d == 0)
        {
            printf("%lld\n",d);
            while(n%d == 0)//n%0 then Floating Point Exception
            {
              
                n/=d;
                
            }
           
        }

    }
    if(n>1)
        printf("%lld\n",n);
    
    
}
int main()
{
    long long int n;
    scanf("%lld",&n);

    primefactorize(n);  
    
    return 0;
}


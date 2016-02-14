/**
 * SPOJ Problem Set (classical)
 * 11736. Prime Time
 * Problem code: PTIME
 *
 * For your math homework this week your teacher gave you five large
 * numbers and asked you to find their prime factors. However these
 * numbers aren't nearly large enough for someone with knowledge of
 * programming like yourself. So you decide to take the factorial of
 * each of these numbers. Recall that N! (N factorial) is the product
 * of the integers from 1 through N (inclusive). It.s your job now to
 * create a program to help you do your homework.
 * Input
 *
 * Each test case contains a number N (2 . N . 10000).
 *
 *  
 *  Output
 *
 *  The output should contain a line representing the prime
 *  factorization of the factorial given number, which should be of
 *  the form: p1^e1 * p2^e2 * ... * pk^ek where p1, p2, ..., pk are
 *  the distinct prime factors of the factorial of the given number in
 *  increasing order, and e1, e2, ..., ek are their exponents.
 *
 *   
 *   Example
 *
 *    
 *
 *    Input:
 *
 *    10
 *
 *    Output:
 *
 *    2^8 * 3^4 * 5^2 * 7^1
 *
 *
 *    */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define Lim 10010
#define sqrtLim 101
#define Num 1231
using namespace std;
vector<bool> b((Lim-3)>>1);
int p[Num];
void opt_sieve()
{
    int cnt;
    for(int i=3;i<=sqrtLim;i+=2)
    {
        if(!b[(i-3)>>1])
        {
            for(int j=i*i;j<=Lim;j+=i)
            {
                if(j & 1) // odd
                {
                    b[(j-3)>>1]=1;
                }
            }
        }
    }
    p[1]=2;
    for(int i=0,cnt=2;cnt<=Num;i++)
        if(!b[i])
            p[cnt++]=2*i+3;
}

void prime_fact_factorize(int n)
{
    int count;

    int index=lower_bound(p,p+1230,n) - p; 
    
    if(p[index] != n)
        index=index-1;

    index-=1;   

    for(int i=1;p[i]<=n;i++)//check prime factor in factorial
    {
        count=0;
        
        for(int j=p[i];j<=n;j*=p[i])
        {
            count+=floor(n/j);



        }
        printf("%d^%d",p[i],count);
   
        if(index)
            printf(" * ");
        index--;
    }
    printf("\n");
}

int main()
{
    int n;
    opt_sieve();
    //for(int i=0;i<12;i++)
      //  cout<<p[i]<<endl;
    while(scanf("%d",&n) != EOF)
    {
        prime_fact_factorize(n);
    }
    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 5699. The last digit re-visited
 * Problem code: LASTDIG2
 *
 * Pappu was doing the work of his math class about three days but he
 * is tired of make operations a lot and he should deliver his task
 * tomorrow. His math.s teacher gives two numbers a and b. The problem
 * consist in find the last digit of the potency of base a and index
 * b. Help Pappu with his problem. You are given two integer numbers:
 * the base a (number of digits d, such that 1<=d<=1000) and the index
 * b (0 <= b <= 922*10^15). You
 * have to find the last digit of a^b.
 *
 *                                                          Input
 *                                                          The first
 *                                                          line of
 *                                                          input
 *                                                          contains
 *                                                          an integer
 *                                                          t, the
 *                                                          number of
 *                                                          test cases
 *                                                          (t <= 30).
 *                                                          t test
 *                                                          cases
 *                                                          follow.
 *                                                          For
 *                                                          each test
 *                                                          case will
 *                                                          appear a
 *                                                          and b
 *                                                          separated
 *                                                          by space.
 *
 *                                                                                                                   Output
 *                                                                                                                   For
 *                                                                                                                   each
 *                                                                                                                   test
 *                                                                                                                   case
 *                                                                                                                   output
 *                                                                                                                   an
 *                                                                                                                   integer
 *                                                                                                                   per
 *                                                                                                                   line
 *                                                                                                                   representing
 *                                                                                                                   the
 *                                                                                                                   result.
 *
 *                                                                                                                   Example
 *                                                                                                                   Input:
 *                                                                                                                   3
 *                                                                                                                   3
 *                                                                                                                   10
 *                                                                                                                   6
 *                                                                                                                   2
 *                                                                                                                   150
 *                                                                                                                   53
 *                                                                                                                   Output:
 *                                                                                                                   9
 *                                                                                                                   6
 *                                                                                                                   0
 *                                                                                                                   */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[1001];
int main()
{
    int t;
    long long int a,b,l,pwr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %lld",str,&b);
        l=strlen(str);
        
        a=str[l-1]-'0';//last digit of a

        if(b==0)
            {printf("1\n");continue;}
        
        b=(b%100)%4;

        if(b==0)  //for 2^4 =16 (last digit not 1)
            b=4;

        pwr=(long long int)pow(a,b);
        printf("%lld\n",pwr%10);
    }
    return 0;
}


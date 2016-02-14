/**
 * SPOJ Problem Set (tutorial)
 * 13209. Divisors
 * Problem code: KIDZEE1J
 *
 * Print all the divisors of a given number.
 *
 * .... ....... ..... ....... (......) ... .... ....
 * Input
 *
 * First line of input contains the number of test case T (T . 10).
 * Then each of the next T lines contains a single integer N, (1 . N .
 * 100000).
 *
 * ..... ...... ..... ..... ..... ..... ..... ...... T (T.10). ......
 * ....... T ...... ...... ......... .... ... ..... ...... N ....., (1
 * . N . 100000).
 * Output
 *
 * For each case print one line of output containing the case number
 * first, then, all the divisors of N in increasing order. Each
 * divisor must be printed exactly once. The divisors must be
 * separated by single space character and there must not be any
 * trailing spaces.
 *
 * ....... ..... .... .... ... .... ....... .... ..., ...... ....
 * ..... .... .... .... N .. ... ....... ... .... .. ...... ...... ...
 * ... ....... ....... ......... ..... ...... .... ....... ......
 * ......... .... ..... .... ..... .... ... ... ...... .... ....
 * ........ ..... ..... ...
 * Example
 *
 * Input:
 *
 * 3 6 15 23
 *
 * Output:
 *
 * Case 1: 1 2 3 6 Case 2: 1 3 5 15 Case 3: 1 23
 *
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,cases=0;
    scanf("%d",&t);
    while(t--)
    {
       cases++;
       scanf("%d",&n);
       printf("Case %d: ",cases);

       for(int i=1;i<=n;i++)
       {
           if(n%i==0)
           {
               printf("%d ",i);
           }
       }
       printf("\n");
    }
    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 4141. Euler Totient Function
 * Problem code: ETF
 *
 * English  Vietnamese
 *
 * In number theory, the totient of a positive integer n is defined to
 * be the number of positive integers less than or equal to n that are
 * coprime to n.
 *
 * Given an integer n (1 <= n <= 10^6). Compute the value of the
 * totient .
 * Input
 *
 * First line contains an integer T, the number of test cases. (T <=
 * 20000)
 *
 * T following lines, each contains an integer n.
 * Output
 *
 * T lines, one for the result of each test case.
 * Example
 *
 * Input:
 * 5
 * 1
 * 2
 * 3
 * 4
 * 5
 *
 * Output:
 * 1
 * 1
 * 2
 * 2
 * 4
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long double primefactorize(int n)
{
   // int count;
    long double  pro=1.0;
    for(int d=2;d*d<=n;d++)
    {
        if(n%d == 0)
        {
           // count=0;
            while(n%d == 0)
            {
              //  count++;
                n/=d;
             }
            pro*=(1-1/(double)d);
        }
    }
    if(n>1)
        pro*=(1-1/(double)n);

    return pro;
}
int main()
{
    int n,t;
    long double pro;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
       pro = primefactorize(n);
      // cout<<pro<<endl;
       pro*=n;
       printf("%.0Lf\n",pro);
    }
    return 0;
}


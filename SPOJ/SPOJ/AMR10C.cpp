/**
 * SPOJ Problem Set (classical)
 * 8057. Square Free Factorization
 * Problem code: AMR10C
 *
 * You all know about factorization of an integer.  Here we want you
 * to factor a number into as few factors as possible.  That is easy,
 * you say, just have the number itself, and that will be the smallest
 * number of factors i.e. 1.
 * But wait, I haven't finished -- each of the factors that you find
 * must be square-free.  A square-free number, however you factor it,
 * won't have any factor that is a perfect square.  Of course, you can
 * never include 1 as a factor.
 *  
 *  INPUT
 *  The first line of input is the number of test cases T.
 *  The next T lines each have an integer N.
 *   
 *   OUTPUT
 *   For each testcase, output the smallest number of square-free
 *   factors.
 *    
 *    CONSTRAINTS
 *    T <= 1e4
 *    2 <= N <= 1e6
 *     
 *     SAMPLE INPUT
 *     2
 *     6
 *     8
 *      
 *      SAMPLE OUTPUT
 *      1
 *      3
 *      */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define Lim 1000001
using namespace std;
int a[Lim];
void squaresieve()
{
    int temp;
    for(int i=2;i*i<=Lim;i++) // go upto sqrt(Lim)
    {
        if(!a[i])  // a[i] is 0
        {
            temp=i*i;
            for(int j=i*i;j<=Lim;j+=temp)
            {
                //j is square multiples
                a[j] = i ;//storing greatest square free factor
            }
        }
    }

}
int main()
{
    squaresieve();
    int t,n,count;
    scanf("%d",&t);
    while(t--)
    {
        count=1;
        scanf("%d",&n);
        while(a[n] != 0)
        {
            count++;
            n /= a[n];
        }
        printf("%d\n",count);
    }
    return 0;
}


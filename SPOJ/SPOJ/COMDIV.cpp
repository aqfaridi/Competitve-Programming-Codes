/**
 * SPOJ Problem Set (classical)
 * 7718. Number of common divisors
 * Problem code: COMDIV
 *
 * You will be given T (T<=10^6) pair of numbers. All you have to tell
 * is the number of common divisors between two numbers in each pair.
 * Input
 *
 * First line of input: T (Number of test cases)
 * In next T lines, each have one pair A B (0<A,B<=10^6)
 * Output
 *
 * One integer describing number of common divisors between two
 * numbers.
 * Example
 *
 * Input:
 *
 * 3
 * 100000 100000
 * 12 24
 * 747794 238336
 *
 *
 *
 *
 * Output:
 *
 * 36
 * 6
 * 2
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
int primefactorize(int n)
{
    int no_of_divisors=1,count;

    for(int d=2;d*d<=n;d++)
    {
        if(n%d == 0)
        {
            count=0;
            while(n%d == 0)//n%0 then Floating Point Exception
            {
                count++;
                n/=d;
            }
            no_of_divisors*=(count+1);
        }

    }
    if(n>1)
        no_of_divisors*=(1+1);
    
    return no_of_divisors;
}
int main()
{
    int t,a,b,c,no_of_divisors;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        c=gcd(a,b); // c <= a and b
        //cout<<c<<endl;
        no_of_divisors=primefactorize(c);
        printf("%d\n",no_of_divisors);
    }
    return 0;
}


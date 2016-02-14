/**
 * SPOJ Problem Set (classical)
 * 5917. Factorial length
 * Problem code: LENGFACT
 *
 * Given integer n, print length of n! (which is factorial of n).
 * Input
 *
 * The first line of the standard input contains one integer t
 * (t<10001) which is the number of test cases.
 *
 * In each of the next t lines there is number n (0<=n<=5*10^9).
 * Output
 *
 * For each test, print the length of n! (which is factorial of n).
 * Example
 *
 * Input:
 * 3
 * 1
 * 10
 * 100
 * Output:
 * 1
 * 7
 * 158
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long long int a;
    while(t--)
    {
        scanf("%lld",&a);
        if(a==0||a==1||a==2) printf("1\n");
        else printf("%lld\n",(long long int)floor((log(2*acos(-1)*a)/2+a*(log(a)-1))/log(10))+1);
    }
    return 0;
}

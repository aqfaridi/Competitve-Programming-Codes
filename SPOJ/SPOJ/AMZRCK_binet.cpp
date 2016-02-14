/*
 *  *              F(n) = [ph^n - (1-ph)^n] / sqrt(5);
 *   *              PH 1.618033989
 *    *              and sum of n terms fibonaicci   n+2 th term -1
 *     *
 *      */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long double ph1=1.618033989;

long double power(long double a,unsigned long long b)
{
    long double res=1;

    while(b>0)
    {
        if(b%2==1)
            res*=a;
        a*=a;
        b=b/2;
    }

    return res;
}

int main()
{
    unsigned long long  test=0,n=0,fibn=0;
    long double r2=0.0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        ph1=(1.0 + sqrt(5) ) / 2.0;
        r2=power(ph1,n+2);//phi to power n
        fibn=round((r2)/sqrt(5));
        printf("%lld\n",fibn);
    }
    return 0;
}



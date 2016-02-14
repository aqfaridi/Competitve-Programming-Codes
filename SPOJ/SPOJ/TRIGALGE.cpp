/**
 * SPOJ Problem Set (classical)
 * 10712. Easy Calculation
 * Problem code: TRIGALGE
 *
 * Find x such that Ax+Bsin(x)=C.
 * Input
 *
 * The first line denotes T(number of test cases). 3T integers follow
 * denoting A,B and C for every test case. (A>=B>0). All Integers are
 * less than 100000.
 * Output
 *
 * T real numbers rounded to 6 digits one in each line.
 * Example
 *
 * Input:
 * 1
 *
 * 1 1 20
 *
 * Output:
 * 19.441787
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a,b,c;
double F(double x)
{
    return (a*x + b* sin(x) -c);
}
int main()
{
    int t,count;
    double x,x1,x2;
    scanf("%d",&t);
    while(t--)
    {
        x1=0;x2=1000;
        x=(x1 + x2)/2.0;
        scanf("%d %d %d",&a,&b,&c);
        count=100;
       // while(fabs((x1-x2)/((x1+x2)/2)) > 0.0000005)
        while(count--)
        {
            if(F(x1) * F(x) < 0)
            {
                x2=x;
                x=(x1+x2)/2.0;
            }
            else if(F(x) * F(x2) < 0)
            {
                x1=x;
                x=(x1+x2)/2.0;
            }
        }
        printf("%.6lf\n",x);

    }

    return 0;
}


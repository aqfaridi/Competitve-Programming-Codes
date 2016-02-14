/**
 * SPOJ Problem Set (classical)
 * 3442. The last digit
 * Problem code: LASTDIG
 *
 * Nestor was doing the work of his math class about three days but he
 * is tired of make operations a lot and he should deliver his task
 * tomorrow. His math.s teacher gives two numbers a and b. The problem
 * consist in find the last digit of the potency of base a and index
 * b. Help Nestor with his problem. You are given two integer numbers:
 * the base a (0 <= a <= 20) and the index b (0 <= b <=
 * 2,147,483,000), a and b both are not 0. You have to find the last
 * digit of a^b.
 * Input
 *
 * The first line of input contains an integer t, the number of test
 * cases (t <= 30). t test cases follow. For each test case will
 * appear a and b separated by space.
 * Output
 *
 * For each test case output an integer per line representing the
 * result.
 * Example
 *
 * Input:
 * 2
 * 3 10
 * 6 2
 *
 * Output:
 * 9
 * 6
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long int power(int n,int expo)
{
    long long int pro=1;
    for(int i=0;i<expo;i++)
    {
        pro*=n;
    }
    return pro;
}
int main()
{
    int t,a,b,pwr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(b==0)
        {printf("1\n");continue;}

        pwr=b%4;

        if(pwr == 0)
            pwr=4;

        printf("%lld\n",power(a,pwr)%10);
    }
    return 0;
}


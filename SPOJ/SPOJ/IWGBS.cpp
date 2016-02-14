/**
 * SPOJ Problem Set (classical)
 * 10676. 0110SS
 * Problem code: IWGBS
 *
 * Dor is IWGolymp student so he has to count in how many ways he can
 * make N digit numbers that is formed by ones and zeroes.But zeroes
 * can not be next to each other .Help to him in how many differnt
 * numbers can he make .
 *
 * ex:3
 *
 * 101,010,111,110,011
 * Input
 *
 * A number N    N<=10000
 * Output
 *
 * Answer for the problem
 * Example
 *
 * Input:
 * 2
 * Output:
 * 3
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000000
long double fibo[MAX];
using namespace std;
void fibonacci()
{
    for(int i=2;i<MAX;i++)
        fibo[i]=fibo[i-1]+fibo[i-2];
}
int main()
{
    fibo[0]=fibo[1]=1;
    fibonacci();
    int n;
    scanf("%d",&n);
    printf("%Lf\n",fibo[n+1]);
    return 0;
}


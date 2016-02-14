/**
 * SPOJ Problem Set (classical)
 * 9952. 111.1 Squared
 * Problem code: GUANGGUN
 *
 * We call an integer Sticks if its decimal representation contains
 * only digit 1.
 *
 * Let S(n) be the sticks with n digits, find the sum of digits of
 * S(n)2
 *
 * For example, S(9)2=12345678987654321, its sum of digits is 81.
 * Input
 *
 * Each line contains an integer represents n(1 . n . 1018).
 *
 * Input is terminated by EOF, and contains at most 100 lines.
 * Output
 *
 * For each n, print an integer represents the answer.
 * Example
 *
 * Input:
 * 9
 * 10
 *
 * Output:
 * 81
 * 82
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long int n,sum;
    while(scanf("%lld",&n) != EOF)
    {
        sum=n*n; // (n*(n-1)/2) + (n*(n-1)/2)
        printf("%lld\n",sum);
    }

    return 0;
}


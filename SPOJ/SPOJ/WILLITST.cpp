/**
 * SPOJ Problem Set (classical)
 * 9948. Will it ever stop
 * Problem code: WILLITST
 *
 * When Bob was in library in University of Warsaw he saw on one of
 * facades caption :"Will it ever stop?" and below some mysterious
 * code:
 *
 * while n > 1
 *   if n mod 2 = 0 then
 *       n:=n/2
 *         else
 *             n:=3*n+3
 *
 *             Help him finding it out !
 *
 *             Input
 *
 *             In first line one number n<=10^14.
 *             Output
 *
 *             Print "TAK" if program will stop, otherwise print "NIE"
 *             Example
 *
 *             Input:
 *             4
 *
 *             Output:
 *             TAK
 *
 *             */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long int n;
    scanf("%lld",&n);
    if((n & (n-1)) == 0)
        printf("TAK\n");
    else 
        printf("NIE\n");

    return 0;
}


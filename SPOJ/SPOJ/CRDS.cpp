/**
 * SPOJ Problem Set (classical)
 * 10509. Cards
 * Problem code: CRDS
 *
 * Maricruz have a lot of cards, she always uses her cards to build
 * pyramids as shown
 * in the following image:
 * A pyramid card of 3 leves.
 * She always wonder how many cards does she need to make a pyramid
 * card of N
 * levels. Your task is to answer that question.
 * Input
 * The first line of the input contains an integer 1<= T <= 1,000.
 * Each of the
 * following T lines will have an integer 1<= N <= 1,000,000.
 * Output
 * For each case, output a single line consisting of the number of
 * cards needed to
 * build a pyramid card of level N modulo 1,000,007.
 *
 *
 * Input Example
 * 2
 *
 * 3
 *
 * 7
 * Output Example
 * 15
 * 77
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000007
using namespace std;
int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        n=n*(3*n+1)/2;
        n%=MOD;
        printf("%lld\n",n);
    }
    return 0;
}


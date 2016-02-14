/**
 * SPOJ Problem Set (classical)
 * 11933. DIAGONAL
 * Problem code: DIG
 *
 * You are a given a n sided convex polygon. Find total number of
 * intersections of all diagonals.
 *
 * Assume that all the intersection points are different.
 *
 * If in case answer exceeds 10^9 + 7 , take modulo 10^9 + 7
 *
 * 1<=n<=10^8
 * Input
 *
 * First Line : T (no of test cases)
 *
 * Next T line will contain N no of vertices
 * Output
 *
 * No of intersections of diagonals as specified.
 *
 *  
 *  
 *  Example
 *
 *  Input:
 *  2
 *  4
 *  5
 *   Output:
 *
 *   1
 *   5
 *   */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

int main()
{
    int t,n;
    long long int a,b,nC4;
   // long long int MOD=24*1000000007;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=(n*(n-1))%MOD;
        b=(a*(n-2))%MOD;
        nC4=(b * (n-3))%MOD;
        nC4=nC4*modulo(24,MOD-2,MOD);
        printf("%lld\n",nC4/MOD);
    }
    return 0;
}


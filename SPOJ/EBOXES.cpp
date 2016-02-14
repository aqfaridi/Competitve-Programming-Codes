/**
 * SPOJ Problem Set (classical)
 * 4343. Empty Boxes
 * Problem code: EBOXES
 *
 * N large empty boxes (assume they are of type:1) are initially
 * placed on a table. An unknown number of boxes (type:1) are selected
 * and in each of them K smaller boxes (type:2) are placed. Again an
 * unknown number of type:2 boxes are selected and K boxes of type:3
 * are placed inside. This process is repeated T times. Now a box is
 * assumed to be empty when it has no smaller boxes inside it. Finally
 * after all the processes are complete let there be F empty boxes in
 * total.
 * LIMITS
 * 1< N,K,T,F <1000000
 * Input
 *
 * First line of the input file contains the number of test cases.
 * Then each line contains 4 integers N,K,T,F as described above.
 * Output
 *
 * Each line should contain the total number of boxes on the table.
 * Example
 *
 * Input:
 * 1
 * 11 8 2 102
 *
 * Output:
 * 115
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
    long long n,k,T,f;
    long long sumofrand,total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&n,&k,&T,&f);
        sumofrand = (f-n)/(k-1);
        total = n + k*sumofrand;
        printf("%lld\n",total);
    }
    return 0;
}


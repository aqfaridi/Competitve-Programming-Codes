/**
 * SPOJ Problem Set (classical)
 * 7430. Tower Of Hanoi - Revisited
 * Problem code: RANJAN02
 *
 * Given 3 three pegs: leftmost peg A, middle peg B and rightmost peg
 * C.Find the shortest sequence of moves that transfers a tower of n
 * disks from the left peg A to the right peg C, if direct moves
 * between A and C are disallowed. (Each move must be to or from the
 * middle peg B.)
 *
 * Constraints:
 * 1. Initially the left peg A in stacked by n disks in the order of
 * decreasing size.
 * 2. Only one move cand be done at a time and never moving a larger
 * one onto a smaller.
 * 3. Number of moves will always be less than 2^64.
 * 4. 1 <= n <= 35
 * Input
 *
 * Input begins with a integer t, followed by t lines. Each line has
 * the no. of pegs n.
 * Output
 *
 * For each test case, output the minimum no. of move required to
 * transfer the n disks from peg A to peg C.
 * Example
 *
 * Input:
 * 4
 * 1
 * 2
 * 5
 * 10
 *
 * Output:
 * 2
 * 8
 * 242
 * 59048
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long int power(int n)
{
    long long int product=1;
    for(int i=0;i<n;i++)
        product*=3;

    return product;
}    
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",power(n)-1);
    }
    return 0;
}


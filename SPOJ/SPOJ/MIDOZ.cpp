/**
 * SPOJ Problem Set (tutorial)
 * 9151. Kids Love Candies
 * Problem code: MIDOZ
 *
 * Your son's birthday is coming soon (assume that you have a son),
 * and you promised to make the best party ever for him. He will be
 * very happy if he can invite all his friends to this party (he has
 * many friends), but unfortunately you can't invite everyone because
 * you have a limited number of candies, and you want everyone to be
 * happy.
 *
 * As we all know, kids love to eat a lot of candies of the same type,
 * let's say a kid will be happy only if he can eat at least K candies
 * of the same type.
 *
 * Given K, and the number of available candies of each type,
 * calculate the maximum number of kids where you can make all of them
 * happy by giving each one at least K candies of the same type.
 * Input
 *
 * Your program will be tested on one or more test cases. The first
 * line of the input will be a single integer T, the number of test
 * cases (1$ \le$T$ \le$100). Followed by the test cases, each test
 * case is on two lines. The first line of each test case contains two
 * integers N, the number of different candies(1$ \le$N$ \le$100), and
 * K, the minimum number of candies which will make a kid happy as
 * described above (1$ \le$K$ \le$100). The second line of each test
 * case contains N integers, separated by a single space, which are
 * the available number of candies of each type. There will be at
 * least 1 candy and at most 100 candies of each type.
 * Output
 *
 * For each test case, print on a single line one integer, the maximum
 * number of kids you are asked to calculate as described above.
 *
 * Example
 *
 * Input:
 *
 * 2
 * 3 2
 * 4 5 7
 * 3 8
 * 4 5 7
 *
 *
 * Output: 7
 *
 * 0
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,k,var,child;
    scanf("%d",&t);
    while(t--)
    {
        child=0;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&var);
            child+=(var/k);
        }
        printf("%d\n",child);
    }
    return 0;
}


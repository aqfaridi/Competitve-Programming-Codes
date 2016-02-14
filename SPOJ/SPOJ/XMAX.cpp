/**
 * SPOJ Problem Set (classical)
 * 8217. XOR Maximization
 * Problem code: XMAX
 *
 * Given a set of integers S = { a1, a2, a3, ... a|S| }, we define a
 * function X on S as follows:
 * X( S ) = a1 ^ a2 ^ a3 ^ ... ^ a|S|.
 * (^ stands for bitwise 'XOR' or 'exclusive or')
 *
 * Given a set of N integers, compute the maximum of the X-function
 * over all the subsets of the given starting set.
 * Input
 *
 * The first line of input contains a single integer N, 1 <= N <= 105.
 * Each of the next N lines contain an integer ai, 1 <= ai <= 1018.
 * Output
 *
 * To the first line of output print the solution.
 * Example
 *
 * Input:
 *
 * 3
 * 1
 * 2
 * 4
 * Output:
 *
 * 7
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
set<long long int> norepeat;
int main()
{
    int n;
    long long int var,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&var);
        norepeat.insert(var);
    }
    for(set<long long int>::const_iterator it=norepeat.begin();it!=norepeat.end();it++)
    {
       sum ^= (*it);
    }
    printf("%lld\n",sum);

    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 7870. Invisible point
 * Problem code: ADV04J
 *
 * Daniel marked a point on a plane with sympathetic ink and he has
 * also drawn a regular n-gon with normal ink. Max can see the n-gon,
 * but can't see the point. Max can draw a line and ask Daniel which
 * side of the line the point is. What is the minimum number of
 * questions Max have to ask to define if the point is inside the
 * n-gon in the worst case?
 * Input
 *
 * First line of the input contains number t - the amount of test
 * cases. Each test consists of the single integer n - the amount of
 * sides of the n-gon.
 * Constraints
 *
 * 1 <= t <= 100
 * 3 <= n <= 1000000
 * Output
 *
 * For each test case print a single number - the anwer to the
 * questiong in the statement.
 * Example
 *
 * Input:
 * 1
 * 4
 *
 * Output:
 * 3
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=ceil(log2(n))+1;
        printf("%d\n",ans);
    }

    return 0;
}


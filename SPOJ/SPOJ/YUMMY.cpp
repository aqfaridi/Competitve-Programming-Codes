/**
 * SPOJ Problem Set (classical)
 * 9686. Yummy Triangular Pizza
 * Problem code: YUMMY
 *
 * Pizzahat has released a new pizza with triangular shaped pieces.
 * This pizza is composed of some equal-sized equilateral triangle.
 * Moreover, all the triangles are connected. Also, if two triangles
 * are directly connected, they must share a common edge.
 *
 * How many different shapes of this kind of N-pieces pizza are there?
 * Two patterns are considered as same if they can completely overlap
 * after rotation and shifting (note that flipping is not included).
 * Input
 *
 * There are multiple test cases. The first line of input contains a
 * single integer denoting the number of test cases.
 *
 * For each test case, there is only one line with only one integer N
 * denoting the number of pieces that can be used. (1 <= N <= 16)
 * Output
 *
 * For each test case, output a single integer denoting the number of
 * possible different shapes of the pizza.
 * Example
 *
 * Input:
 * 3
 * 2
 * 4
 * 10
 *
 * Output:
 * Case #1: 1
 * Case #2: 4
 * Case #3: 866
 *
 * This problem is first (and only) solved by team Cabbage (Zhongnan
 * University) at 225 minutes after the onsite contest starts. (They
 * have 1 wrong try before they get Accepted.)
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[]={0,1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};
int main()
{
    int t,n,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        printf("Case #%d: %d\n",cases,arr[n]);
    }


    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 11573. A Famous ICPC Team
 * Problem code: TEAM2
 *
 * Mr. B, Mr. G, Mr. M and their coach Professor S are planning their
 * way to Warsaw for the ACM-ICPC World Finals. Each of the four has a
 * square-shaped suitcase with side length Ai (1 <= i <= 4)
 * respectively. They want to pack their suitcases into a large square
 * box. The heights of the large box as well as the four suitcases are
 * exactly the same. So they only need to consider the large box.s
 * side length. Of course, you should write a program to output the
 * minimum side length of the large box so that the four suitcases can
 * be put into the box without overlapping.
 * Input
 *
 * Each test case contains only one line containing 4 integers Ai (1<=
 * i <=4, 1<= Ai <=1,000,000,000) indicating the side length of each
 * suitcase.
 * Output
 *
 * For each test case, display a single line containing the case
 * number and the minimum side length of the large box required.
 * Example
 *
 * Input:
 * 2 2 2 2
 * 2 2 2 1
 *
 * Output:
 * Case 1: 4
 * Case 2: 4
 *
 * Explanation
 *
 * For the first case, all suitcases have size 2x2. So they can
 * perfectly be packed in a 4x4 large box without wasting any space.
 *
 * For the second case, three suitcases have size 2x2 and the last one
 * is 1x1. No matter how to rotate or move, you could find the side
 * length of the box must be at least 4.
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long int arr[4],cases=0;
    while(scanf("%lld %lld %lld %lld",&arr[0],&arr[1],&arr[2],&arr[3]) !=EOF )
    {
        cases++;
        sort(arr,arr + 4);
        printf("Case %lld: %lld\n",cases,arr[2]+arr[3]);
    }
    return 0;
}


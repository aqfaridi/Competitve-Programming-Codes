/**
 * SPOJ Problem Set (classical)
 * 4408. Build a Fence
 * Problem code: FENCE1
 *
 * There is a wall in your backyard. It is so long that you can.t see
 * its endpoints. You want to build a fence of length L such that the
 * area enclosed between the wall and the fence is maximized. The
 * fence can be of arbitrary shape, but only its two endpoints may
 * touch the wall.
 * Input
 *
 * The input consists of several test cases.
 *
 * For every test case, there is only one integer L (1<=L<=100),
 * indicating the length of the fence.
 *
 * The input ends with L=0.
 * Output
 *
 * For each test case, output one line containing the largest area.
 * Your answer should be rounded to 2 digits after the decimal point.
 * Example
 *
 * Input:
 * 1
 * 0
 *
 * Output:
 * 0.16
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,L;
    double area;
    while(1)
    {
        scanf("%d",&L);
        if(L==0)
            break;
        area=L*L/(2.0 * M_PI);
        printf("%.2lf\n",area);
    }

    return 0;
}


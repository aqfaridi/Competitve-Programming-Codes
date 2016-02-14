/**
 * SPOJ Problem Set (classical)
 * 8670. THE MAX LINES
 * Problem code: MAXLN
 *
 * In this problem you will be given a half-circle. The half-circle.s
 * radius is r. You can take any point A on the half-circle and draw 2
 * lines from the point to the two sides of the diameter(AB and AC).
 * Let the sum of square of one line.s length and the other line.s
 * length is s.
 *                           
 *
 *                           Like in the figure s=AB^2+AC. And BC=2r.
 *
 *                           Now given r you have to find the maximum
 *                           value of s. That is you have to find
 *                           point A such that AB^2+AC is maximum.
 *
 *                           Input:
 *                           First line of the test case will be the
 *                           number of test case T(1<=T<=1000) . Then
 *                           T lines follows. On each line you will
 *                           find a integer number r(1<=r<=1000000);
 *                           each representing the radius of the
 *                           half-circle.
 *
 *                           Output:
 *                           For each input line, print a line
 *                           containing .Case I: ., where I is the
 *                           test case number and the maximum value of
 *                           s. Print 2 digit after decimal(Errors
 *                           should be less then .01).
 *
 *                           Sample Input:
 *                           1
 *                           1
 *
 *                           Sample Output:
 *                           Case 1: 4.25
 *                           */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,cases=1;
    scanf("%d",&t);
    int r;
    while(t--)
    {              
        scanf("%d",&r);
        double p;
        p=(((16.0)*r*r)+1.0)/(4.0);
        printf("Case %d: %.2lf\n",cases,p);
        cases++;
    }
    return 0;
}


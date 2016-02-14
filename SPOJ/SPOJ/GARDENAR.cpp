/**
 * SPOJ Problem Set (classical)
 * 5240. Area of a Garden
 * Problem code: GARDENAR
 *
 * One rich person decided to make himself a great garden. The garden
 * should have a from of equilateral triangle. There should be a
 * gazebo inside the garden. The gazebo will be connected with the
 * triangle vertexes by roads. The lengths of all three roads are
 * known. Those numbers are sacred for this rich man. The expense of
 * building such a garden will depend on the area of the garden. Help
 * the rich man by calculating what will be the area of his garden.
 * Input
 *
 * The first line of the input contains number t . the amount of
 * tests. Then t test descriptions follow. Each test consist of three
 * integers a, b, c - the lengths of the roads. It is guaranteed that
 * it's possible to build such a garden.
 * Constraints
 *
 * 1 <= t <= 1000
 * 1 <= a, b, c <= 1000
 * Output
 *
 * For each test print the area of the garden with two digits in the
 * fractional part.
 * Example
 *
 * Input:
 * 1
 * 3 4 5
 *
 * Output:
 * 19.83
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,d,e,f;
    double a1,a2,a3,area,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&d,&e,&f);
        s=(d+e+f)/2.0;
        a1=sqrt(3)*d*d/4;
        a2=sqrt(3)*e*e/4;
        a3=sqrt(3)*f*f/4;
        area=0.5*(a1+a2+a3+3*sqrt(s*(s-d)*(s-e)*(s-f)));
        printf("%.2lf\n",area);        
        
    }
    return 0;
}


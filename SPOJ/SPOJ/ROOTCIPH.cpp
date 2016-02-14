/**
 * SPOJ Problem Set (classical)
 * 6297. Decipher
 * Problem code: ROOTCIPH
 *
 * Radar scanned the approaching enemy aircraft on the border. However
 * due to some error part of the tranmitted data can't be deciphered.
 * It was possible only to obtain the coefficients of the cubic
 * polynomial, whose roots are the coordinates of the aircraft
 * relative to the radar. Now you need to calculate the distance to
 * the aircraft. Write the program to solve this task.
 * Input
 *
 * The first line contains T (1 <= T <= 1000) - number tests. The next
 * T lines contain three integers a, b and c - coefficients of the
 * polynomial x3 + ax2 + bx + c, whose roots are the coordinates (the
 * absolute value of the coordinates do not exceed 108).
 * Output
 *
 * For each test print the square of the distance to the enemy
 * aircraft.
 * Example
 *
 * Input:
 * 1
 * -6 11 -6
 *
 *  Output:
 *  14
 *
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    
    int a,b,c,t;
    long long int dist;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        dist=a*a-2*b;
        printf("%lld\n",dist);

    } 

    return 0;
}


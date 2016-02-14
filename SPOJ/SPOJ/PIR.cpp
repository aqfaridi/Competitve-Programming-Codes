/**SPOJ Problem Set (classical)
 * 23. Pyramids
 * Problem code: PIR
 *
 * Recently in Farland, a country in Asia, the famous scientist Mr.
 * Log Archeo discovered ancient pyramids. But unlike those in Egypt
 * and Central America, they have a triangular (not rectangular)
 * foundation. That is, they are tetrahedrons in the mathematical
 * sense. In order to find out some important facts about the early
 * society of the country (it is widely believed that the pyramid
 * sizes are closely connected with Farland's ancient calendar), Mr.
 * Archeo needs to know the volume of the pyramids. Unluckily, he has
 * reliable data about their edge lengths only. Please, help him!
 * Input
 *
 * t [number of tests to follow] In each of the next t lines six
 * positive integer numbers not exceeding 1000 separated by spaces
 * (each number is one of the edge lengths of the pyramid ABCD). The
 * order of the edges is the following: AB, AC, AD, BC, BD, CD.
 * Output
 *
 * For each test output a real number - the volume, printed accurate
 * to four digits after decimal point.
 * Example
 *
 * Input:
 *
 * 2
 * 1 1 1 1 1 1
 * 1000 1000 1000 3 4 5
 *
 * Output:
 *
 * 0.1179
 * 1999.9937
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long sqr(long long a)
{
    return a*a;
}

int main()
{
    long long s, u, v, w, U, V, W;
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &W, &U, &v, &V, &u, &w);
        u = sqr(u); v = sqr(v); w = sqr(w);
        U = sqr(U); V = sqr(V); W = sqr(W);
        s = 4*u*v*w - u*sqr(v+w-U) - v*sqr(u+w-V) - w*sqr(u+v-W);
        s += (u+v-W)*(u+w-V)*(v+w-U);
        printf("%.4lf\n", sqrt(s) / 12);
    }
    return 0;
}


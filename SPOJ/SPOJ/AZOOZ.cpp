/**
 * SPOJ Problem Set (tutorial)
 * 13677. Azooz
 * Problem code: AZOOZ
 *
 * Azooz is a trainee in acmASCIS Level 1 and he just got his Mid Year
 * Vacation. Since he is a naughty boy he often goes to the kitchen
 * when no one at home to play with matches (and to eat of course :D),
 * after many failed attempts to burn down the House, Azooz got bored
 * and wanted to do something new with the matches.
 *
 * The Idea Azooz got is that he builds larger triangles using equal
 * sized triangles formed by the matches he got, so a simple triangle
 * with only one level needs only three matches and another one with
 * two levels needs 9 matches and so on.
 *
 * Triangle with 1 levelTriangle with two levels
 *
 * The two figures illustrate the examples discussed above, and you
 * should know the Number of Matches Azooz needs to complete his
 * Triangle.
 * Input
 *
 * First line of input contains number of test cases T (1<T<50),
 * followed by T lines each of which contains non-negative integer N,
 * in which N < 100, N denotes the level which Azooz wants to build
 * the triangle.
 * Output
 *
 * For each test case print"Case_#i:_X" where "i" is the case number
 * (starting with 1), "X" is number of matches needed to build
 * intended triangle and "_" is a white space. Each test case should
 * be on a separate line.
 * Example
 *
 * Input:
 *
 * 2
 * 1
 * 2
 *
 * Output:
 * Case #1: 3
 * Case #2: 9
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
    int t,n,cases=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",cases,3*n*(n+1)/2);
        cases++;

    }
    return 0;
}


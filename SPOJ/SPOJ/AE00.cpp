/**
 * SPOJ Problem Set (classical)
 * 4300. Rectangles
 * Problem code: AE00
 *
 * Byteman has a collection of N squares with side 1. How many
 * different rectangles can he form using these squares?
 *
 * Two rectangles are considered different if none of them can be
 * rotated and moved to obtain the second one. During rectangle
 * construction, Byteman can neither deform the squares nor put any
 * squares upon any other ones.
 * Input
 *
 * The first and only line of the standard input contains one integer
 * N (1 . N . 10000).
 * Output
 *
 * The first and only line of the standard output should contain a
 * single integer equal to the number of different rectangles that
 * Byteman can form using his squares.
 * Example
 *
 * For the input data:
 *
 * 6
 *
 * the correct result is:
 *
 * 8
 *
 * Task author: Jakub Radoszewski.
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,temp,ans=0;
    scanf("%d",&n);
    for(int i=0;;i++)
    {
        temp=n/(i+1);
        if(temp <= i)
            break;
        ans+=(temp-i);

    }
    printf("%d\n",ans);
    return 0;
}


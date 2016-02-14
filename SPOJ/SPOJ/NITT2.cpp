/**
 * SPOJ Problem Set (classical)
 * 12319. hai jolly jolly jolly
 * Problem code: NITT2
 *
 * Alp and gaut are like always opposite to each other. Once alp told
 * that he can identify a number which is divisble by 252 (He knows
 * because that is his girlfriends birthday - 25/2). Now to come up
 * against alp, gaut said he can identify whether the number is
 * divisble by 525 (poor gaut don't have a girl friend though). The
 * truth is they don't know to do it for big numbers.  So you are here
 * to help them with a method. Given a number you have to tell whether
 * the number is divisble by 252 and 525
 * Input
 *
 * Number of testcases in first line, T. T <= 100.
 *
 * Each line contains one number N, whose divisibility is to be
 * tested. 1 <= N <= 10^50000
 * Output
 *
 * each line containing two Yes/No. one for 252 and one for 525.
 * Example
 *
 * Input:
 * 4
 * 252
 *
 * 525
 *
 * 1179630648
 * 1234623983
 * 16884
 *
 * 21347
 *
 * Output:
 * Yes No
 *
 * No Yes
 *
 * Yes No
 *
 * No No
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[50010];
void divisible252()
{
    int r1=0,r2=0;
    for(int i=0;str[i];i++)
    {
        r1=r1*10 + (str[i]-'0');
        r2=r2*10 + (str[i]-'0');

        r1 %= 252;
        r2 %= 525;
    }
    if(r1==0)
        printf("Yes ");
    else 
        printf("No ");

    if(r2==0)
        printf("Yes\n");
    else 
        printf("No\n");

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        divisible252();
    }
    return 0;
}


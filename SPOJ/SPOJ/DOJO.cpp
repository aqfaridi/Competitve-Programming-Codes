/**
 * SPOJ Problem Set (classical)
 * 11601. With a Pit of Death
 * Problem code: DOJO
 *
 * Leo is training his martial arts in byteland's dojo.
 * The dojo is a rectangular ( n ×m ) area with a pit of death, a
 * square located at (i, j), where 1 <= i <= n, and 1 <= j <= m.
 * Every night, battles are very hard and the dojo is destructed, and
 * reconstructed during the day around the pit.
 * Every evening, Leo's first mission is to make in place tatamis ( 2
 * ×1 ) in the new dojo.
 * Tatamis should cover the whole dojo except the pit of death.
 * Sometimes it's possible, sometimes not!
 *
 *
 * Input
 *
 * The input begins with the number T of test cases in a single line.
 * In each of the next T lines there are four integer numbers n, m, i
 * and j.
 * Output
 *
 * For each test case, print the answer of the problem : "Possible."
 * or "Impossible.".
 * Example
 *
 * Input:
 * 2
 * 3 3 2 2
 * 3 3 1 2
 *
 *
 * Output:
 * Possible.
 * Impossible.
 *
 * Constraints
 *
 * 1 <= T <= 1 000
 * 1 <= i <= n <= 32
 * 1 <= j <= m <= 102000
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
    int t,n,i,mm,jj;
    int lastm,lastj;
    char m[2001],j[2001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s %d %s",&n,m,&i,j);
         
        mm=strlen(m)-1;
        jj=strlen(j)-1;



        lastm=m[mm]-'0';
        lastj=j[jj]-'0';
        if( (n&1)==1  && (lastm & 1)==1 )  //both m and n are odd   
        {
            if( (((i + lastj)%10) & 1) == 0 )   //i+j is even
                printf("Possible.\n");
            else
                printf("Impossible.\n");

        } 
        else    
                printf("Impossible.\n");
         
    }//while
    return 0;
}


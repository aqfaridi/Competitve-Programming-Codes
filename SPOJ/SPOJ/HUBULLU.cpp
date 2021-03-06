/**
 * SPOJ Problem Set (classical)
 * 1028. Hubulullu
 * Problem code: HUBULLU
 *
 * After duelling in quake (a multiplayer game), Airborne and Pagfloyd
 * decide do test themselves out in another game called Hubulullu. The
 * rules of the game are as follows:
 *
 * N wooden pieces (marked with numbers 1 to N) are placed in a
 * transparent bottle. On his turn the first player takes out some
 * piece (numbered x) and all the pieces numbered by divisors of x
 * that are present in the transparent bottle. The second player picks
 * another number and removes it and its divisors as well. Play
 * continues in an alternating fashion until all pieces have been
 * removed from the bottle. The player who removes the last piece from
 * the bottle wins the game.
 *
 * Both players play optimally. Given N (the number of wooden pieces
 * in the transparent bottle initially) and the name of the player who
 * starts the game, determine the winner.
 * Input
 *
 * The first line of the input contains an integer t, the number of
 * test cases. t test cases follow.
 *
 * Each test case consists of a single line containing two integers
 * separated by a single space. The first integer is N (1 <= N <=
 * 2000000000), indicating the number of pieces, and the second
 * integer indicates the player who starts - "0" means Airborne starts
 * the game and "1" means Pagfloyd starts the game (quotes for
 * clarity).
 * Output
 *
 * For each test case output one line containing either "Airborne
 * wins." or "Pagfloyd wins."
 *
 * For each N, it's possible to determine a winner if both players
 * play optimally.
 * Example
 *
 * Input:
 * 1
 * 1 0
 *
 * Output:
 * Airborne wins.
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    
    int t,a,b;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(b==0)
            printf("Airborne wins.\n");
        else
            printf("Pagfloyd wins.\n");
    }
    return 0;
}


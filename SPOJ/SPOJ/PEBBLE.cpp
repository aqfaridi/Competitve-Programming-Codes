/**
 * SPOJ Problem Set (classical)
 * 7668. Pebble Solver
 * Problem code: PEBBLE
 *
 * Pebble is a popular turn-based multi-player game played by kids. In
 * this game, all the players are given a binary string (i.e., a
 * string consisting only of 0's and 1's) of some fixed length. The
 * goal of the game is to convert this binary string to a string
 * containing all 0's.
 *
 * In a turn, a player is allowed to perform only one operation:-
 * Replace a 1 by a 0 or vice-versa. But each such operation will flip
 * the states of all the bits following the bit you changed.
 *
 * Take for example, the string: 1001010. You decide to flip the 1
 * located at the 4th position. The new string after the operation
 * will be : 1000101. (Note that 5th to 7th bits flipped as a result
 * of flipping the 4th bit.)
 *
 * Your small sister loves to play this game very much. So, you decide
 * to gift her the pebble-solver software which solves this game with
 * the minimum number of operations(how else will you make sure that
 * she always wins?!). And we want to make sure that your software
 * doesn't have any bugs. (he he)
 * Input
 *
 * There are going to multiple test cases. Each test case consists of
 * a single line which is the initial bit-string.
 * Output
 *
 * Output corresponding to the each test case in the following format
 * :
 *
 * "Game #x: y", where x indicates the test case number and y is the
 * minimum number of steps required for your program to solve the
 * game.
 * Example
 *
 * Input:
 * 0101
 * 10000
 * 00
 *
 * Output:
 * Game #1: 3
 * Game #2: 2
 * Game #3: 0
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1001];
int main() {
    int t,l,count,cases=0;

    while(scanf("%s",str) != EOF)
    {
        cases++;
        l=strlen(str);
        count=0;
        for(int i=0;i<l;i++)
        {
            count++;
            while(str[i]==str[i+1])
                i++;
        }

        if(str[0]=='0')
            count--;
            
        printf("Game #%d: %d\n",cases,count);
    }


    return 0;
}

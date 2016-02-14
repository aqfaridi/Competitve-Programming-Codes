/**
 * SPOJ Problem Set (classical)
 * 6694. D - Playing with Marbles
 * Problem code: BOMARBLE
 *
 * PROBLEM D
 *
 *  PLAYING WITH MARBLES
 *
 *  Pablo was assigned in his class to construct pentagons inside
 *  pentagons with marbles but he doesn.t know how many marbles he
 *  will need. He knows that for one pentagon he needs 5 marbles
 *
 *  Imagen2 
 *
 *  The only way he knows to insert a second pentagon is putting a
 *  marble in the middle of each segment and drawing three lines as
 *  shown. He puts a marble in the intersecting lines and removes
 *  them. To insert a third pentagon inside he first divides all
 *  segments in two including the ones that are not needed, and
 *  repeats the procedure. Drawing a second pentagon will require 12
 *  marbles. A third pentagon will require 22 marbles. Given the
 *  information of how many pentagons will be created, write a program
 *  to calculate the number of marbles needed.
 *
 *  Input
 *
 *  The input contains several test cases. Each test case contains one
 *  integer N indicating the number of pentagons to create
 *  (1<=N<=103). The end of input is indicated by a line containing
 *  only one zero.
 *
 *  Output
 *
 *  For each test case in the input, your program must print a single
 *  line, containing one single integer, the number of marbles
 *  required. 
 *
 *  Sample Input
 *
 *  1
 *
 *  2
 *
 *  3
 *
 *  0
 *
 *  Sample Output
 *
 *  5
 *
 *  12
 *
 *  22
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long pentagonalnumber;
   
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        n=n-1;
        pentagonalnumber=(10*(n+1) + 3*n*(n+1) -2*n)/2; //(3*n*n - n)/2;
        printf("%lld\n",pentagonalnumber);
    }
    return 0;
}


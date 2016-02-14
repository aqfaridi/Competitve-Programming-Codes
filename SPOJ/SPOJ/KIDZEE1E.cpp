/**
 * SPOJ Problem Set (tutorial)
 * 13203. Sort them All
 * Problem code: KIDZEE1E
 *
 * Given 3 distinct numbers, print them in ascending order.
 *
 * ..... .... ...... .... ...... ...... ... .... .. ..... ....... ....
 * ....
 * Input
 *
 * First line contains the test case number T (T <= 10). Each line
 * contains three integers, n1, n2, n3. None of them are greater than
 * 1000 and all three are distinct.
 *
 * ..... ...... ..... ..... ..... ..... ..... ...... T (T<=100). .....
 * ....... ..... ..... ... ..... ...... n1, n2, n3 ..... ....
 * ......... ......... ... 1000 .. .... .. ....
 * Output
 *
 * For each case print the case number starting from 1 and then print
 * the three given numbers in ascending order. Two consecutive numbers
 * must be separated by exactly one space. See sample input output for
 * more details.
 *
 * ....... ..... .... .... ... ... ..... ....... .... .... .....
 * ....... ..... ........ ... .... .. ..... ...... ....... .... ....
 * ........ ..... ....... .... ......... .... ..... ....... .... ....
 * ..... ....... ... ......... ..... .....
 * Example
 *
 * Input:
 *
 * 3 3 2 1 1 2 3 10 5 6 Output:
 *
 * Case 1: 1 2 3 Case 2: 1 2 3 Case 3: 5 6 10
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
int arr[3];
using namespace std;
int main()
{
    int t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        for(int i=0;i<3;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+3);
        printf("Case %d: ",cases);
        for(int i=0;i<3;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}


/**
 *
SPOJ Problem Set (tutorial)
13995. Missing Number
Problem code: MISSING

Given two numbers N and K, consider the following sequence of N integers:

K, K + 1, K + 2, ., K + N - 1 

You will be given N - 1 of those integers in any order, and you will have to find the missing number in the sequence.
Input

The first line of input contains two numbers separated by one space, N and K, where 1 < N <= 107 and 1 <= K <= 231-1.

The second line contains N . 1 integers from the sequence specified above, with one space between each integer. The N . 1 numbers are arranged in no particular order. One of the numbers in the sequence is missing.
Output

Output a single line containing the missing number in the sequence.
Example

Input 1:

5 4

5 4 7 6

Output 1:
8

Input 2:

3 2

4 2

Output 2:

3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long sum,n,k,var;
    scanf("%lld %lld",&n,&k);
    sum=n*(2*k + (n-1))/2;
    for(int i=0;i<n-1;i++)
    {
        scanf("%lld",&var);
        sum -= var;
    }
    printf("%lld\n",sum);
    return 0;
}


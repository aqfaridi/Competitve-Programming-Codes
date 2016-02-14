/**
 * SPOJ Problem Set (tutorial)
 * 500. Turbo Sort
 * Problem code: TSORT
 *
 * Given the list of numbers, you are to sort them in non decreasing
 * order.
 * Input
 *
 * t . the number of numbers in list, then t lines follow [t <= 10^6].
 * Each line contains one integer: N [0 <= N <= 10^6]
 * Output
 *
 * Output given numbers in non decreasing order.
 * Example
 *
 * Input:
 *
 * 5
 * 5
 * 3
 * 6
 * 7
 * 1
 *
 * Output:
 *
 * 1
 * 3
 * 5
 * 6
 * 7
 *
 * */
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() 
{
   int n;
   scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   sort(arr,arr+n);
   for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
   return 0;
} 

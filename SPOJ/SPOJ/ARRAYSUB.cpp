/**
 * SPOJ Problem Set (classical)
 * 10582. subarrays
 * Problem code: ARRAYSUB
 *
 * Given an array and an integer k, find the maximum for each and
 * every contiguous subarray of size k.
 * Input
 *
 * the number n denoting number of elements in the array then after a
 * new line we have the numbers of the array
 *
 * and then k in a new line
 *
 * n<10^6
 *
 * k<10^5
 *
 * 1 <= k <=n
 *
 * and each element of the array is between 0 and 10^6
 * Output
 *
 * print the output array
 * Example
 *
 * Input:
 * 9
 *
 * 1  2  3  1  4  5  2  3  6
 * 3
 * Output:
 * 3 3 4 5 5 5 6
 *
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
    int n,k,max=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);
    int temp[k];
    for(int i=0;i<k;i++)
        temp[i]=arr[i];

    sort(temp,temp+k); 

    max=temp[k-1];
    printf("%d",max);
    for(int i=k;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        printf(" %d",max);
    }
    printf("\n");
    
    return 0;
}


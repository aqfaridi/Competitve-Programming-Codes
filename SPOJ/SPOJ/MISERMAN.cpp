/**
 * SPOJ Problem Set (classical)
 * 7588. Wise And Miser
 * Problem code: MISERMAN 
 *
 *
 * Jack is a wise and miser man. Always tries to save his money.
 *
 * One day, he wants to go from city A to city B. Between A and B,
 * there are N number of cities(including B and excluding A) and in
 * each city there are M buses numbered from 1 to M. And the fare of
 * each bus is different. Means for all N*M busses, fare (K) may be
 * different or same. Now Jack has to go from city A to city B
 * following these conditions:
 *
 * At every city, he has to change the bus.
 *
 * And he can switch to only those buses which have number either
 * equal or 1 less or 1 greater to the previous.
 *
 * You are to help Jack to go from A to B by spending the minimum
 * amount of money.
 *
 * N,M,K<=100.
 *
 * Input
 * Line 1:    N M
 * Line 2:    NxM Grid
 *
 * Each row lists the fares the M busses to go form the current city
 * to the next city.
 *
 * Output
 * Single Line containing the minimum amount of fare that Jack has to
 * give.
 *
 * Example
 * Input:
 * 5 5
 * 1 3 1 2 6
 * 10 2 5 4 15
 * 10 9 6 7 1
 * 2 7 1 5 3
 * 8 2 6 1 9
 *
 * Output:
 * 10
 *
 * Explanation: 
 * 1->4->1->3->1 = 10
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int arr[110][110];  // k (fare) values store here
int main()
{
    int n,m,minfare;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        arr[i][0]=INT_MAX;
    for(int i=0;i<n;i++)
        arr[i][m+1]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            arr[i][j] += min(arr[i-1][j],min(arr[i-1][j-1],arr[i-1][j+1]));
        }
    }
    
    minfare=INT_MAX;
    for(int j=1;j<=m;j++)
        if(arr[n-1][j] < minfare)
            minfare=arr[n-1][j];
    printf("%d\n",minfare);
    
    return 0;

}


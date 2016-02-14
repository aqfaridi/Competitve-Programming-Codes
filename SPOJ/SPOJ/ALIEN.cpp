/**
 * SPOJ Problem Set (classical)
 * 9861. Hotels Along the Croatian Coast
 * Problem code: HOTELS
 *
 * There are N hotels along the beautiful Adriatic coast. Each hotel
 * has its value in Euros.
 *
 * Sroljo has won M Euros on the lottery. Now he wants to buy a
 * sequence of consecutive hotels, such that the sum of the values of
 * these consecutive hotels is as great as possible - but not greater
 * than M.
 *
 * You are to calculate this greatest possible total value.
 * Input
 *
 * In the first line of the input there are integers N and M (1 . N .
 * 300 000, 1 . M < 231).
 *
 * In the next line there are N natural numbers less than 106,
 * representing the hotel values in the order they lie along the
 * coast.
 * Output
 *
 * Print the required number (it will be greater than 0 in all of the
 * test data).
 * Example
 * input
 *
 * 5 12
 * 2 1 3 4 5
 *
 * output
 *
 * 12
 *
 *      input
 *
 *      4 9
 *      7 3 5 6
 *
 *      output
 *
 *      8
 *      */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[MAX];
int main()
{
    int n,m,q=0,t;
    long long int sum=0,result=0;
    scanf("%d",&t);
 while(t--)
 {
     q=0;sum=0;result=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count=0,actual_count=0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        
        if(sum > m)  //check on each insertion of new element to sum
        {
            while(sum > m)
            {
             
                sum -= arr[q];
                q++;
                
            }
        }
        count= (i+1) - q;
      
        if(q==i)
            continue;

        if(count > actual_count  || (count==actual_count && sum < result))  // sum already sum < m
        {
            result = sum;
            actual_count=count;
        }

    }
    printf("%lld %d\n",result,actual_count);

 } 
    return 0;
}


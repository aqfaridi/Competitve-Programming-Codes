/**
 * SPOJ Problem Set (classical)
 * 10565. Alice Sieve
 * Problem code: ALICESIE
 *
 *  
 *  Alice has recently learned to use the Sieve of Eratosthenes, an
 *  ancient algorithm for finding all
 *  prime numbers up to any given limit. As expected, she was really
 *  impressed by it's simplicity and
 *  elegancy.
 *  Now, she has decided to design her own sieve method: The Sieve of
 *  Alice, formally defined by the
 *  following procedure, which determines the Sieve of Alice up to a
 *  given limit N.
 *  1. Create a list of consecutive integers from N to 2 (N, N-1, N-2,
 *  ..., 3, 2). All of those N-1
 *  numbers are initially unmarked.
 *  2. Initially, let P equal N, and leave this number unmarked.
 *  3. Mark all the proper divisors of P (i.e. P remains unmarked).
 *  4. Find the largest unmarked number from 2 to P – 1, and now let P
 *  equal this number.
 *  5. If there were no more unmarked numbers in the list, stop.
 *  Otherwise, repeat from step 3.
 *  Unfortunately, Alice has not found an useful application for it's
 *  Sieve. But she still wants to know,
 *  for a given limit N, how many integers will remain unmarked.
 *
 *   
 *
 *   Alice has recently learned to use the Sieve of Eratosthenes, an
 *   ancient algorithm for finding all
 *
 *   prime numbers up to any given limit. As expected, she was really
 *   impressed by it's simplicity and
 *
 *   elegancy.
 *
 *   Now, she has decided to design her own sieve method: The Sieve of
 *   Alice, formally defined by the
 *
 *   following procedure, which determines the Sieve of Alice up to a
 *   given limit N.
 *
 *   1. Create a list of consecutive integers from N to 2 (N, N-1,
 *   N-2, ..., 3, 2). All of those N-1
 *
 *   numbers are initially unmarked.
 *
 *   2. Initially, let P equal N, and leave this number unmarked.
 *
 *   3. Mark all the proper divisors of P (i.e. P remains unmarked).
 *
 *   4. Find the largest unmarked number from 2 to P – 1, and now let
 *   P equal this number.
 *
 *   5. If there were no more unmarked numbers in the list, stop.
 *   Otherwise, repeat from step 3.
 *
 *   Unfortunately, Alice has not found an useful application for it's
 *   Sieve. But she still wants to know,
 *
 *   for a given limit N, how many integers will remain unmarked.
 *
 *    
 *
 *     
 *     Input
 *
 *      
 *
*      The first line contains an integer T, the number of test cases
*      (1 ≤ T ≤ 104) . Each of the next T lines
*
*      contains an integer N ( 2 ≤ N ≤ 106).
*
*       
*       Output
*
*        
*
*        Output T lines, one for each test case, containing the
*        required answer.
*
*         
*         Example
*
*         Input:
*         3
*         2
*         3
*         5
*
*         Output:
*         1
*         2
*         3
*         */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
   int count,n,t;
   scanf("%d",&t);
   while(t--)
   {
       count=0;
       scanf("%d",&n);
       
       int *arr=new int[n+1];

       for(int i=0;i<=n;i++)
           arr[i]=1;

       arr[0]=arr[1]=0;
       for(int i=n;i>=2;i--)
       {
           if(arr[i]==1)
           {
                for(int j=i-1;j>=2;j--)
                {
                    if((i % j)==0 )//j divisor of i
                        arr[j]=0;
                }
           }
       }

       for(int i=0;i<=n;i++)
       {
           if(arr[i] == 1)
               count++;
       }
  
       printf("%d\n",count);
       delete arr;
   }
    return 0;
}


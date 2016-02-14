/**
 * SPOJ Problem Set (classical)
 * 12407. Johnny The Gambler
 * Problem code: LCPC12F
 *
 * Johnny is a gambling addict. He entered a casino and started
 * playing a game with the dealer. The game is as follows: the dealer
 * deals a sequence of N cards, each card containing a number C[i] and
 * asks Johnny how many pairs (j, k) such that j < k and C[j] + C[k] =
 * X. If Johnny answers correctly he wins, otherwise the dealer wins.
 *
 * Input Format         
 *
 * The first line of input contains an integer T, the number of test
 * cases. T test cases follow, Each test case start with the value of
 * 0 <= X <= 2*103 followed by the number of cards 0 < N <= 105
 * followed by N numbers representing the numbers on the cards 0 <=
 * C[i] < 103.
 *
 * Output Format
 *
 * There should be T lines, containing the following format.
 *
 * k. S
 *
 * Where k is the test case number (starting at 1), a single period, a
 * single space and S representing the number of valid pairs (j, k) as
 * described above.
 *
 * Sample Input
 *  
 *  Sample Input
 *
 *  1
 *
 *  10 3 1 5 9
 *      
 *
 *      1. 1*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100020
using namespace std;
long long  arr[MAX];
//long long freq[MAX];
int main()
{
    bool b;
    int t,cases=0;
    long long zero,X,n,count,total;
    scanf("%d",&t);
    while(t--)
    {
        zero=0;
        cases++;
        scanf("%lld %lld",&X,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i] == 0)
                zero++;
        }
        if(X==0)
        {
            printf("%d. %lld\n",cases,zero);
            continue;
        }        
        sort(arr,arr+n);
        /*
        for(int i=0;i<n-1;i++)
        {
            count = 1;
            while(arr[i]==arr[i+1])
            {    
                count++;
                i++;
            }
            freq[arr[i]]=count;
        }
        for(int i=0;i<20;i++)
            cout<<freq[i]<<" ";
        cout<<endl;
        */
        count=0;
        total=0;
        b=false;
        /*
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        */
        for(int i=0;i<n-1;i++)
        {  
           //b = binary_search(arr + i+1 ,arr + n,X-arr[i]);
           long long *location = lower_bound(arr+i+1,arr+n,X-arr[i]);
           long long index = location - arr;
           //cout<<arr[i]<<" "<<X-arr[i]<<endl;
           if(arr[index]== (X-arr[i]))
           {
               //found
               //cout<<arr[index]<<" "<<index<<" "<<X-arr[i]<<" ";
               count=1;
               while(arr[index] == arr[index+1])
               {
                   count++;
                   index++;
               }
              // cout<<count<<endl;
               total += count; 
           }
           /*
           if(b)
           {
               //cout<<i<<"  "<<arr[i]<<endl;
               count += freq[X - arr[i]];
           }
           */
           
        }
        printf("%d. %lld\n",cases,total);
    }
    return 0;
}


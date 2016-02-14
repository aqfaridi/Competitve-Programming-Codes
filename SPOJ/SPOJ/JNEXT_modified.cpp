/**
 * SPOJ Problem Set (classical)
 * 12150. Just Next !!!
 * Problem code: JNEXT
 *
 *
 * JUST NEXT !!!
 * DevG likes too much fun to do with numbers. Once his friend Arya
 * came and gave him a challenge, he gave DevG an array of digits
 * which is forming a number currently (will be called as given
 * number). DevG was challanged to find the just next greater number
 * which can be formed using digits of given number. Now DevG needs
 * your help to find that just next greater number and win the
 * challenge.
 * Input: 
 * The first line have t number of test cases (1<=t<=100). In next 2*t
 * lines for each test case first there is number n (1<=n<=1000000)
 * which denotes the number of digits in given number and next line
 * contains n digits of given number separated by space.
 * Output:
 * Print the just next greater number if possible else print -1 in one
 * line for each test case.
 * Note : there will be no test case which contains zero in starting
 * digits of any given number.
 * Sample Test Cases :
 * Input : 
 * 2
 * 5
 * 1 5 4 8 3
 * 10
 * 1 4 7 4 5 8 4 1 2 6
 * Output :
 * 15834
 * 1474584162
 * Time Limit : 2 sec
 *
 *
 * DevG likes too much fun to do with numbers. Once his friend Arya
 * came and gave him a challenge, he gave DevG an array of digits
 * which is forming a number currently (will be called as given
 * number). DevG was challanged to find the just next greater number
 * which can be formed using digits of given number. Now DevG needs
 * your help to find that just next greater number and win the
 * challenge.
 *
 *
 * Input: 
 *
 *
 * The first line have t number of test cases (1<=t<=100). In next 2*t
 * lines for each test case first there is number n (1<=n<=1000000)
 * which denotes the number of digits in given number and next line
 * contains n digits of given number separated by space.
 *
 *
 * Output:
 *
 *
 * Print the just next greater number if possible else print -1 in one
 * line for each test case.
 *
 *
 * Note : There will be no test case which contains zero in starting
 * digits of any given number.
 *
 *
 * Sample Test Cases :
 *
 *
 * Input : 
 *
* 2
*
* 5
*
* 1 5 4 8 3
*
* 10
*
* 1 4 7 4 5 8 4 1 2 6
*
*
* Output :
*
* 15834
*
* 1474584162
* */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1000001];
int main()
{
    int t,n;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=false;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i-1] < a[i])
            {
                sort(a+i,a+n);
                swap(a[i-1],*upper_bound(a+i,a+n,a[i-1]));
                sort(a+i,a+n);
                flag=true;
                break;
            }
        }
        if(flag)
            for(int i=0;i<n;i++)
                printf("%d",a[i]);
        else
            printf("-1");

        printf("\n");

    }
    return 0;
}


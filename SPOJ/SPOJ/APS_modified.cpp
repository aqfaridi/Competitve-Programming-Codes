/**
 * SPOJ Problem Set (classical)
 * 13753. Amazing Prime Sequence
 * Problem code: APS
 *
 * Bablu is very fond of Series and Sequences...
 *
 * After studying Fibonacci Series in Class IX, he was impressed and
 * he designed his own sequence as follows...
 *
 * a[0] = a[1] = 0 
 *
 * For n > 1, a[n] = a[n - 1] + f(n), where f(n) is smallest prime
 * factor of n.
 *
 * He is also very fond of programming and thus made a small program
 * to find a[n], but since he is in Class IX, he is not very good at
 * programming. So, he asks you for help. Your task is to find a[n]
 * for the above sequence....
 * Input
 *
 * Your code will be checked for multiple Test Cases.
 *
 * First Line of Input contains T (<= 100), the number of Test Cases.
 *
 * Next T lines contain a single number N. (1 < N < 10^7).
 * Output
 *
 * Single line containing a[n] i.e. nth number of the sequence for
 * each test case.
 * Example
 *
 * Input:
 * 3
 *
 * 2
 *
 * 3
 *
 * 4
 *
 * Output:
 * 2
 *
 * 5
 *
 * 7 
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 10000000
#define sqrtMax 3163
using namespace std;

long long int a[MAX];

int arr[MAX];

int main()
{

    for(int i=0;i<MAX;i++)
        arr[i]=i;

    for(int i=2;i<=sqrtMax;i++)
    {
        if(arr[i]==i)
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                if(arr[j]==j) //check if already i filled
                    arr[j]=i;
            }

        }

    }




    a[0]=a[1]=0;
    for(int i=2;i<MAX;i++)
        a[i]=a[i-1]+arr[i];





    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}


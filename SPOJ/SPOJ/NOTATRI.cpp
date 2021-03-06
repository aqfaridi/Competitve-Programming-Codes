/**
 * SPOJ Problem Set (classical)
 * 2905. Not a Triangle
 * Problem code: NOTATRI
 *
 * You have N (3 . N . 2,000) wooden sticks, which are labeled from 1
 * to N. The i-th stick has a length of Li (1 . Li . 1,000,000). Your
 * friend has challenged you to a simple game: you will pick three
 * sticks at random, and if your friend can form a triangle with them
 * (degenerate triangles included), he wins; otherwise, you win. You
 * are not sure if your friend is trying to trick you, so you would
 * like to determine your chances of winning by computing the number
 * of ways you could choose three sticks (regardless of order) such
 * that it is impossible to form a triangle with them.
 * Input
 *
 * The input file consists of multiple test cases. Each test case
 * starts with the single integer N, followed by a line with the
 * integers L1, ..., LN. The input is terminated with N = 0, which
 * should not be processed.
 * Output
 *
 * For each test case, output a single line containing the number of
 * triples.
 * Example
 *
 * Input:
 * 3
 * 4 2 10
 * 3
 * 1 2 3
 * 4
 * 5 2 9 6
 * 0
 *
 * Output:
 * 1
 * 0
 * 2
 *
 * For the first test case, 4 + 2 < 10, so you will win with the one
 * available triple. For the second case, 1 + 2 is equal to 3; since
 * degenerate triangles are allowed, the answer is 0.
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[2010];
int main()
{
    int n,sum;
    while(1)
    {
        sum=0;
        scanf("%d",&n);
        if(n==0)
            break;

        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        for(int i=0;i<(n-1);i++)  //consider nc2 duplets excl. last index number  
        {
            for(int j=i+1;j<(n-1);j++)
            {
                int *location = upper_bound(arr,arr+n,arr[i]+arr[j]);
                int index = location - arr;              
               
                if(index < n)
                {
                    sum += (n-index); //all impossible triangle after index since array is sorted
                    
                }

            }
        }
        printf("%d\n",sum);
    }


    return 0;
}


/**
 * SPOJ Problem Set (tutorial)
 * 74. Divisor Summation
 * Problem code: DIVSUM
 *
 * Given a natural number n (1 <= n <= 500000), please output the
 * summation of all its proper divisors.
 *
 * Definition: A proper divisor of a natural number is the divisor
 * that is strictly less than the number.
 *
 * e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the
 * divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.
 *
 * Input
 *
 * An integer stating the number of test cases (equal to about
 * 200000), and that many lines follow, each containing one integer
 * between 1 and 500000 inclusive.
 * Output
 *
 * One integer each line: the divisor summation of the integer given
 * respectively.
 * Example
 *
 * Sample Input:
 * 3
 * 2
 * 10
 * 20
 *
 * Sample Output:
 * 1
 * 8
 * 22
 *
 * Warning: large Input/Output data, be careful with certain languages
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,count,nn;
    long long int sumd;
    scanf("%d",&t);
    while(t--)
    {
        sumd=1;
        scanf("%d",&n);
        nn=n;
       //prime factorization********************/
        for(int d=2;d*d<=n;d++)
        {
            if(n%d==0)
            {
                count=0;
                while(n%d==0)
                {
                    count++;
                    n/=d;
                }
           //     cout<<d<<" "<<count<<endl;
                sumd*=(long long int)(pow(d,count+1)-1)/(d-1);
           //     cout<<sumd<<endl;
            }
        }
        if(n>1)
           sumd*=(long long int)(pow(n,1+1)-1)/(n-1);
        /*******************************************/

      
        printf("%lld\n",sumd-nn);
    }
    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 10293. FANCY NUMBERS
 * Problem code: FANCY
 *
 *
 *
 * FANCY NUMBERS
 *  
 *
 *  Girls usually give only missed calls to their boyfriends and they
 *  want them to call back. These boys are now busy with their
 *  engineering subjects and cannot remember all girl friends. mobile
 *  number. Because of this, girls make it easy for them by having
 *  fancy mobile numbers. A fancy mobile number may contain many
 *  continuous digits in it.
 *
 *  For example 9994442200 is a fancy mobile number because the boy
 *  can remember simply as triple nine, triple four, double two and
 *  double zero. As they are engineering students they do think
 *  different. One of the engineering students can spell the above
 *  number as double nine, nine, four, double four, two, two, double
 *  zero.
 *
 *  The number 100 has only 2 possibilities as it can be spelt as
 *  either one, zero, zero (or) one, double zero
 *
 *  Given a mobile number find the number of possibilities that the
 *  number can be remembered.
 *
 *
 *  Input Specification:
 *
 *  The first line consists of an integer t denoting the number of
 *  test cases. Each test case consists of a mobile number of length
 *  <= 30 digits.
 *
 *  Output Specification:
 *
 *  For each test case output the number of possibilities the number
 *  can be remembered.
 *
 *  Input Constraints: 1<=t<=100000
 *  Sample Input:
 *  3
 *
 *  100
 *
 *  12345
 *
 *  11112
 *
 *
 *  Sample Output:
 *
 *  2
 *
 *  1
 *
 *  8
 *
 *  WARNING:  Huge data set! Make your I/O optimizations.
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char num[35];
long long int expo(int a,int n)
{
    long long int result=1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n/=2;
    }
    return result;
}
int main()
{
    int t,l,count;
    long long int now;
    scanf("%d",&t);
    while(t--)
    {   
        now=1;
        scanf("%s",num);
        l=strlen(num);
        for(int i=0;i<l-1;i++)
        {
            count=1;
            if(num[i]==num[i+1])
            {
                count=1;
                while(num[i]==num[i+1])
                {
                    count++;
                    i++;
                }
            }
            now *= expo(2,count-1);
        }
        printf("%lld\n",now);               

    }
    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 6171. Majority
 * Problem code: MAJOR
 *
 * The human tribe has just discovered some other tribe and wants to
 * communicate with them. To make sure it is not intercepted by the
 * terminators, they ask their chief computer engineer Rohit to design
 * a system for the purpose. In the design that Rohit proposes, data
 * is transmitted n times. If it is received more than half-the times,
 * it is said to be successfully transmitted. If not, the data is said
 * to be lost. Rohit obviously got a lot of fame and respect for his
 * work. Nitish doesn.t like it and wants to challenge Rohit.s
 * supremacy. He wants to check out the system and has hired you for
 * the process.
 * Input
 *
 * The first line of the input contains test cases t(1<=t<=100). It is
 * followed by 2*t lines, 2 for each test case. The first line of
 * input for each test case contains a number n (0<=n<=106), followed
 * by n elements in the next line. Each number is from -10^3 to +10^3
 * Output
 *
 * You are required to output .YES. followed by the number
 * transmitted, if it was transmitted successfully, and .NO.
 * otherwise.
 * Example
 *
 * Input:
 *
 * 3
 *
 * 4
 *
 * 2 1 2 2
 *
 * 6
 *
 * 1 1 1 2 2 2
 *
 * 5
 *
 * 1 2 4 5 1
 *
 * Output:
 *
 * YES 2
 *
 * NO
 *
 * NO
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 3000
using namespace std;
int sieve[MAX];
int main()
{
    int t,n,data,var;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        b=false;
        memset(sieve,0,sizeof(sieve));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&var);
            if(var>=0 && var<=1000)
                sieve[var] += 1;
            else if(var < 0 )
                sieve[abs(var)+1000] += 1;

        }
        for(int i=0;i<MAX;i++)
        {
            if(sieve[i] > n/2)
            {
                b=true;
                if(i >=0 && i<=1000)
                    data = i;
                else if(i>1000)
                    data = 1000 - i;

                break;
            }
        }
        if(b)
            printf("YES %d\n",data);
        else
            printf("NO\n");
    }
    return 0;
}


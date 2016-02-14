/**
 * SPOJ Problem Set (classical)
 * 1167. Move To Invert
 * Problem code: MINCOUNT
 *
 * A triangle made of coins of height h is as follows
 * It has h coins at the base and h-1 coins one level above base and
 * so on.(Coins are placed as shown in the figure below)
 * And at the top most level there will be only one coin
 * Now given h the task is to invert this triangle by moving minimum
 * number of coins. For example when h=4 triangle is
 * Invert
 * For h=4 at least 3 coins must be moved to invert it.
 * Input
 *
 * In the first line N will be given and then N lines follow with each
 * line having a integer which is the height of triangle in that test
 * case.00.h<1010;
 * Output
 *
 * For each test case output in a seperate line the minimum number of
 * moves required to invert the triangle. Output fits in long long
 * data type
 * Example
 *
 * Inputt:
 * 1
 * 3
 *
 * Output:
 * 2
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==0 || n==1)
            printf("0\n");
        else if(n==2)
            printf("1\n");
        else if(n==3)
            printf("2\n");
        else if(n==4)
            printf("3\n");
        else
        {
            if((n&1)) // odd n
                n=((n/2-1)*(4+((n/2-2)*2))/2) +3;
            
            else
                n=(((n-2)*(n-2))/4) + 3;

            printf("%lld\n",n);

        }
                    
    }
    return 0;
}


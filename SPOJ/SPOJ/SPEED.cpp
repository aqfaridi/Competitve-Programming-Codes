/**
 * SPOJ Problem Set (classical)
 * 9199. Circular Track
 * Problem code: SPEED
 *
 *  
 *  Two person are running on a circular track either in same
 *  direction or opposite direction indefinitely. The speed of both of
 *  them is given to you. Speed will be positive in clockwise
 *  direction, and negative in anticlockwise direction. Print the
 *  number of distinct points, they will meet on the circle.
 *  Input
 *  First line contains t, number of test cases.
 *  Each test case contains two numbers, S1 and S2 (not equal to zero)
 *  which are the speeds of the two persons. S1 and S2 will be
 *  distinct.
 *  Output
 *  Print in a separate line, the number of distinct points at which
 *  they meet.
 *  Example
 *  Input
 *  2
 *  1 2
 *  1 -1
 *  Output
 *  1
 *  2
 *
 *  Two persons are running on a circular track either in the same
 *  direction or in the opposite direction, indefinitely. The speed of
 *  both of them is given to you. Speed will be positive in clockwise
 *  direction, and negative in anticlockwise direction. Print the
 *  number of distinct points, at which they will meet on the circle.
 *
 *  Input
 *  First line contains t, number of test cases. Each test case
 *  contains two numbers, S1 and S2 (not equal to zero) which are the
 *  speeds of the two persons. S1 and S2 will be distinct.
 *
 *  Output
 *  Print in a separate line, the number of distinct points at which
 *  they meet.
 *
 *  Example
 *
 *  Input
 *  2
 *  1 2
 *  1 -1
 *
 *  Output
 *  1
 *  2
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define max(a,b) (a>b)?a:b
#define min(x,y) (x<y)?x:y
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,s1,s2,ans,mn,mx;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&s1,&s2);

        mx=max(abs(s1),abs(s2));
        mn=min(abs(s1),abs(s2));
        
        if((s1<0 and s2<0 ) or (s1>0 and s2>0))//same dirn
        {
        
            ans=(mx-mn)/gcd(mx,mn);
        }
        else if((s1>0 and s2<0) or (s1<0 and s2>0))
        {
            
            ans=(mx+mn)/gcd(mx,mn);
        }
        printf("%d\n",ans);


    }

    return 0;
}


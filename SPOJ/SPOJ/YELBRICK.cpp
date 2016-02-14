/**
 * SPOJ Problem Set (classical)
 * 10575. The Yellow Brick Road
 * Problem code: YELBRICK
 *
 * After Dorothy.s memorable adventure in the Land of Oz,
 * traffic along the Yellow Brick Road got really intense,
 * making some sections of it nearly impossible to cross because of
 * the holes along the road. The Land of
 * Oz engineers are having trouble to pave this road, because the
 * yellow stone is in short supply, forcing
 * them to buy stones from different suppliers. As you already know,
 * every road in the Land of Oz must be
 * built using bricks that are perfect and identical cubes. To
 * maximize the durability of the road, it also must
 * be built using the least number of bricks possible. The problem is
 * that each supplier provides stones of
 * different sizes, that must be cut in order to make the bricks for
 * the road.
 *
 *
 * Can you help the engineers to find which is the best brick size to
 * use to maximize the road durability?
 * Input
 *
 * Each test case is given using several lines. The first line
 * contains an integer N representing the number of
 * different suppliers of yellow stone (2 . N . 1000). For simplicity,
 * you can assume that the engineers will
 * buy one stone from each supplier. Each of the next N lines contains
 * three integers Ai, Bi, Ci (0 . Ai, Bi, Ci
 * . 1000, 1 . i . N) that describe, respectively, the width, height
 * and depth of each stone provided by the i-
 * th supplier.
 * The last test case is followed by a line containing one zero.
 * Output
 *
 * For each test case, print one line containing the minimum number of
 * identical cubes that can be cut from
 * the given stones.
 * Example
 *
 * Input:
 * 2
 * 1 2 3
 * 4 5 6
 * 2
 * 4 4 4
 * 2 2 2
 * 0
 *
 * Output:
 * 126
 * 9 
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    long long int n,gcd_n;
    long long int sum;
    long long int a[1001],b[1001],c[1001];
    while(1)
    {
        gcd_n=0;
        sum=0;
        scanf("%lld",&n);
        if(n==0)
            break;

        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
            gcd_n=gcd(gcd(gcd(a[i],b[i]),c[i]),gcd_n);            
        }
        for(int i=0;i<n;i++)
        {
           sum += ((a[i]/gcd_n) * (b[i]/gcd_n) * (c[i]/gcd_n));
        }
        printf("%lld\n",sum);


    }

    

    return 0;
}


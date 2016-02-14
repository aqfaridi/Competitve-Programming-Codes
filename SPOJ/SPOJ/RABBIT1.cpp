/**
 * SPOJ Problem Set (classical)
 * 2450. Counting Rabbits
 * Problem code: RABBIT1
 *
 * Rabbits are incredible animals. One of their more interesting
 * characteristics is related with their reproduction. If we keep a
 * couple of adult rabbits in optimal conditions of life, it is
 * scientifically proved that, each month, that couple is capable of
 * procreating a new couple of young rabbits. You should know that
 * only the adult couples may procreate and that the time taken by a
 * young couple of rabbits to grow (that is, to become adult) is of 1
 * month. For the convenience of this task, we will be dealing with
 * immortal rabbits.
 *
 * Farmer Luis (FL) is a great admirer of rabbits. FL bought in the
 * market 1 couple of adult rabbits (alive, of course) and know wants
 * to raise as many rabbits as he can. Unfortunately, there is a
 * little problem, FL has boxes where he can only put exactly 2^M (1
 * <= M <= 20) couples of rabbits (neither more nor less). FL can use
 * as many boxes as he wishes as long as he fulfils the condition
 * above. FL would like to know how many couples of rabbits he will
 * not be able to put inside boxes if he raises rabbits for N (1 <= N
 * <= 2147483647) months and then tries to .box. them (put them inside
 * boxes). You should help FL with these calculations. You must
 * consider that FL starts with 1 adult couple of rabbits the 1st
 * month, and that couples of rabbits reproduce and grow as stated in
 * the 1st paragraph.
 * Input
 *
 * Line 1: C (1 <= C <= 100), the number of calculations your program
 * will be requested to do
 *
 * Lines 2-C+1: two integers N and M (in that order)
 * Output
 *
 * Lines 1-C: on each lines print S, which is the number of rabbits FL
 * will not be able to .box. for calculation # i
 * Example
 *
 * Input:
 * 1
 * 5 2
 *
 * Output:
 * 0
 *
 * Output explanation:
 *
 * After growing couples of rabbits during 5 months, FL has 5 adult
 * couples and 3 young couples (8 couples in total). FL has boxes
 * where can put 2^2 = 4 couples of rabbits, so he can use 2 boxes to
 * .box. all the 8 couples. If FL had instead grown couples of rabbits
 * for 4 months, he would have 5 couples in total; thus 1 couple would
 * have remained un-.boxed. (the answer would have been 1). 
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void multiply(long long int a[][2],long long int b[][2],long long int MOD)
{
    long long int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }

        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=c[i][j];
        }
    }


}
void  power(long long int a[][2],long long int n,long long int m)
{
    long long int result[2][2]={{1,0},{0,1}}; //unity matrix
    while(n>0)
    {
        if((n&1))
            multiply(result,a,m);

        multiply(a,a,m);
        n/=2;
    }
    
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=result[i][j];
}

long long int fibo(long long int n,long long int MOD)
{
    long long int obj_matrix[2][2]={{1,1},{1,0}};
    power(obj_matrix,n-1,MOD);

    return obj_matrix[0][0]%MOD;

}
int main()
{
    long long int t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        m = 1<<m ; // 2^m
        printf("%lld\n",fibo((n+1),m));
        
    }
    return 0;
}



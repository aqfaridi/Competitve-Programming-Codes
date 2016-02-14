/**
 * SPOJ Problem Set (classical)
 * 8001. Fibonacci Sum
 * Problem code: FIBOSUM
 *
 * The fibonacci sequence is defined by the following relation:
 *
 * F(0) = 0
 *
 * F(1) = 1
 *
 * F(N) = F(N - 1) + F(N - 2), N >= 2
 *
 *  
 *
 *  Your task is very simple. Given two non-negative integers N and M,
 *  you have to calculate the sum (F(N) + F(N + 1) + ... + F(M)) mod
 *  1000000007.
 *  Input
 *  The rst line contains an integer T (the number of test cases).
 *  Then, T lines follow. Each test
 *  case consists of a single line with two non-negative integers N
 *  and M.
 *
 *   
 *
 *   The first line contains an integer T (the number of test
 *   cases). Then, T lines follow. Each test case consists of a single
 *   line with two non-negative integers N and M.
 *   Output
 *
 *   For each test case you have to output a single line containing
 *   the answer for the task.
 *   Example
 *
 *   Input:
 *   3
 *   0 3
 *   3 5
 *   10 19
 *
 *   Output:
 *   4
 *   10
 *   10857
 *
 *   Constraints
 *
 *       T <= 1000
 *           0 <= N <= M <= 109
 *           */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
void multiply(long long int a[][2],long long int b[][2],long long int m)
{
    long long int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%m)%m;
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

long long int fibo(long long int n,long long int m)
{
    if(n==0)
        return 0;
    long long int obj_matrix[2][2]={{1,1},{1,0}};
    power(obj_matrix,n-1,m);

    return obj_matrix[0][0]%m;

}
int main()
{
    long long int t,n,m,sum;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld %lld",&n,&m);
        
        //sum of the first n fibonacci number is (n+2)th fibonacci number
        //m terms sum - (n-1) terms sum = n to m terms sum
        //+ MOD for -ve values mod
        sum=(2*fibo(n+2,m)-2-n + m)%m;
        
        printf("%lld\n",sum);
        
    }
    return 0;
}



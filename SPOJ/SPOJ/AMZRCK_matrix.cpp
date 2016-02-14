/**
 * SPOJ Problem Set (classical)
 * 11931. AMZ Word
 * Problem code: AMZSEQ
 *
 * AmzMohammad is a novice problem setter in Spoj. for start of his
 * work he decided to write a classical and sample problem. ( for UI
 * ACM summer program ) 
 *
 * how many N-words(words with n letters) from the alphabet {0,1,2}
 * are such that neighbors differ at most by 1? 
 * Input
 *
 * an integer N.
 * Output
 *
 * Number of N-words with told conditions.
 *
 * answer is less than 1000000000. it is the only constraint :)
 * Example
 *
 * Input:
 * 2
 *
 * Output:
 * 7
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void multiply(long long int a[][2],long long int b[][2])
{
    long long int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
}
void expo(long long int M[][2],long long int n) //M is pointing to original Matrix M
{
    long long int result[2][2]={{1,0},{0,1}};
    while(n>0)
    {
        if((n&1))
            multiply(result,M);

        multiply(M,M);
        n/=2;
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            M[i][j]=result[i][j];    

}

long long int fibo(long long int n)
{
    long long int M[2][2]={{1,1},{1,0}};
    expo(M,n-1);

    return 2*M[0][0] + M[0][1];
}
int main()
{
    long long int n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==0)
            printf("1\n");
        else
            printf("%lld\n",fibo(n));
    }
    return 0;
}


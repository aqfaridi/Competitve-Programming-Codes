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
long long int fibo(long long int n)
{
    if(n==0)
        return 1;
    
    else if(n==1)
        return 3;

    else
        return 2*fibo(n-1) + fibo(n-2);

}
int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n==0)
        printf("0\n");
    else
        printf("%lld\n",fibo(n));
    
    return 0;
}


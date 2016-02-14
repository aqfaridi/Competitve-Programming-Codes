/**
 * SPOJ Problem Set (classical)
 * 6471. Printing some primes
 * Problem code: TDPRIMES
 *
 * The problem statement is really simple. You are to write all primes
 * less than 10^8
 * Input
 *
 * There is not input
 * Output
 *
 * To make the problem less output related write out only the 1st,
 * 101st, 201st, ... 1st mod 100.
 * Example
 *
 * Input:
 *
 * Output:
 * 2
 * 547
 * 1229
 * ...
 * 99995257
 * 99996931
 * 99998953
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MOD 100
#define Lim 100000000
#define sqrtLim 10000
#define Num 5761456
using namespace std;
vector<bool> b((Lim-3)>>1);
vector<int> p(Num);
void opt_sieve()
{
    int cnt;
    for(int i=3;i<=sqrtLim;i+=2)
    {
        if(!b[(i-3)>>1])
        {
            for(int j=i*i;j<Lim;j+=i)
            {
                if(j & 1)  //odd
                     b[(j-3)>>1]=1;   
            }
        }
    }

    p[1]=2;
    for(int i=0,cnt=2;cnt<Num;i++)
    {
        if(!b[i])
            p[cnt++]=2*i+3;
    }
}
int main()
{
    opt_sieve();
    for(int i=1;i<Num;i+=100)
        printf("%d\n",p[i]);
    
    return 0;
}


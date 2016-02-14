/**
 * SPOJ Problem Set (classical)
 * 3505. Prime Number Theorem
 * Problem code: CPRIME
 *
 * English  Vietnamese
 *
 * In number theory, the Prime Number Theorem describes the asymptotic
 * distribution of prime numbers. Let .(x) be the number of prime
 * numbers not greater than x. The Prime Number Theorem states that:
 *
 * Your task is to write a program to verify how well the Prime Number
 * Theorem can estimate .(x). To be more precise, for a given x, you
 * have to calculate the percent error |.(x) - x/lnx| / .(x) %.
 * Input
 *
 * The input contains several test cases (no more than 1000). Each
 * test case contains a value of x (2 . x . 108) given in one line. A
 * number 0 terminates the input.
 * Output
 *
 * For each value of x, output the percent error of the estimation of
 * .(x), rounded to 1 decimal digit.
 * Example
 *
 * Input:
 * 10000000
 * 2
 * 3
 * 5
 * 1234567
 * 0
 *
 * Output:
 * 6.6
 * 188.5
 * 36.5
 * 3.6
 * 7.7
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define Lim 100000000
#define sqrtLim 10000
#define Num 5761456

using namespace std;

vector<bool> b((Lim-3)>>1);//space optimize- max. index required for odd no. only
vector<int> p(Num);   // b and p auto initialize to 0

void opt_sieve()
{
    int cnt;
    for(int i=3;i<=sqrtLim;i+=2)
    {
        if(!b[(i-3)>>1])
        {
            for(int j=i*i;j<=Lim;j+=i)
            {
                if(j & 1 ) //if multiple is odd bcoz we dont have odd numbers corresponding to index
                {
                    b[(j-3)>>1]=1;   //multiple corresponding index assigned to 1
                
                }
            }
        }
    }

    p[1]=2;
    
    for(int i=0,cnt=2;cnt < Num;i++)
       if(!b[i])
          p[cnt++]=2*i+3;//value=index*2 + 3

}
int main()
{
    int n,index;
    vector<int>::iterator location;
    long double theoretical,actual,error;
    opt_sieve();
    
    while(scanf("%d",&n)==1 and n)
    {
        theoretical=n/(log((double)n));
        location=lower_bound(p.begin(),p.end(),n);
        index=location - p.begin();

 
        if(p[index] > n)
            actual=index-1;
        else
            actual=index;
        
       // cout<<actual<<" "<<theoretical<<endl;
        error=fabs( (actual-theoretical) )/actual * 100.0;
    
                
        printf("%.1Lf\n",error);

    }
    return 0;
}


/**
 * SPOJ Problem Set (classical)
 * 13913. Real Mangoes for Ranjith
 * Problem code: MANGOES
 *
 * Ranjith is very fond of mangoes.
 *
 * One fine sunny day, he goes to market to get some mangoes.In the
 * market place, he finds N boxes (indexed from 1 to N), filled with
 * mangoes kept infront of him.
 *
 * Each box indexed i is denoted by bi and contains exactly i mangoes.
 *
 * No of mangoes in bi = mi = i.  
 *
 * Let ti denotes the type of mangoes in box bi (ti is either "real"
 * or "fake")
 *
 * He can choose any box bi (i<=N-2), but he doesn't know if the box
 * contains "real" mangoes or "fake" mangoes i.e. type of box bi.
 *
 * The type of mangoes in bi depends on the number of mangoes in boxes
 * bi,bi+1, bi+2   i.e. {mi, mi+1, mi+2}.
 *
 * Mangoes in box bi are "real" if for each pair of numbers taken from
 * set {mi, mi+1, mi+2}, Greatest common divisor(GCD) equals 1.
 * Otherwise, "fake". Note that ti is not defined for i = N-1 and i =
 * N and assumed to be "fake". 
 *
 * Given N, Ranjith wants to know the total number of "real" mangoes
 * he will get from all boxes. As Ranjith cannot count beyond N,
 * output the result modulo N. 
 * Input
 *
 * Test File starts with number of test cases - T;
 *
 * T lines follows, each containing N, number of boxes.
 * Output
 *
 * Output T lines Number of "real" mangoes Ranjith gets (modulo N) in
 * each one of the T cases.
 * Constraints :
 *
 * 2 < N <= 10^8
 *
 * T <= 10000
 * Example
 *
 * Input:
 *
 * 2
 *
 * 9
 *
 * 5
 *
 * Output:
 *
 * 7
 *
 * 4
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t;
    long long n,sum;
    scanf("%d",&t);
    while(t--)
    {
        
        scanf("%lld",&n);
        /*
        for(int i=1;i<=n-2;i++)
        { 
            if(gcd(i,i+1)==1 && gcd(i,i+2)==1 && gcd(i+1,i+2)==1 )    
            {  sum += i;}

        }*/
        if((n&1)) 
            sum= (n/2)*(0.5)*(2+2*(n/2 -1));
        
        else
            sum=(n-2)*(n-2)/4;

        printf("%lld\n",sum%n);

    }
     
    return 0;
}


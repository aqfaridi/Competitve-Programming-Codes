/**
 * SPOJ Problem Set (classical)
 * 7718. Number of common divisors
 * Problem code: COMDIV
 *
 * You will be given T (T<=10^6) pair of numbers. All you have to tell
 * is the number of common divisors between two numbers in each pair.
 * Input
 *
 * First line of input: T (Number of test cases)
 * In next T lines, each have one pair A B (0<A,B<=10^6)
 * Output
 *
 * One integer describing number of common divisors between two
 * numbers.
 * Example
 *
 * Input:
 *
 * 3
 * 100000 100000
 * 12 24
 * 747794 238336
 *
 *
 *
 *
 * Output:
 *
 * 36
 * 6
 * 2
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
int a[MAX];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
void factorsieve()
{
        for(int i=1;i<MAX;i++)
                    a[i]=i;

        for(int i=2;i*i<=MAX;i++)
        {
           if(a[i] == i)
           {
                for(int j=i*i;j<MAX;j+=i)
                {
                      if(a[j] == j)
                      {
                             a[j]=i;
                      }
                 }
           }

        }
}

int main()
{
    int t,aa,b,n,nod,count,temp;
    scanf("%d",&t);
    factorsieve();
    while(t--)
    {
        nod=1;
        scanf("%d %d",&aa,&b);
        n=gcd(aa,b); // c <= a and b
        if(n==1)
        {printf("1\n");continue;}
        
        temp=a[n];
        n/=a[n];
        count=1;
        while(a[n]!=1)
        {
            //cout<<"temp="<<temp<<" a[n]="<<a[n]<<endl;
            if(temp == a[n])
                count++;
            else
            { 
                temp=a[n];
                nod*=(count+1);
                count=1;
            }
            n/=a[n];
        }
        nod*=(count+1);
        printf("%d\n",nod);
    }
    return 0;
}


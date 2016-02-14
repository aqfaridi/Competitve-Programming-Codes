/**
 * SPOJ Problem Set (classical)
 * 10818. Medium Factorization
 * Problem code: FACTCG2
 *
 * The task in this problem is to write a number in a multiplication
 * of prime numbers separated by . x.. You need to put the
 *
 * number 1 in this multiplication.
 *
 *
 * Input
 *
 * The input consists of several lines.
 *
 * Each line consists of one integer N (1 <= N <= 10^7) .
 *
 *
 * Output
 *
 * For each line you need to output the factorization separated by .
 * x. and including 1.
 *
 *
 * Sample Input
 *
 * 1
 *
 * 2
 *
 * 4
 *
 * 8
 *
 * Sample Output
 * 1
 * 1 x 2
 * 1 x 2 x 2
 * 1 x 2 x 2 x 2
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX  32000
using namespace std;
//int Prime[(int)ceil(1.25506 * MAX/log(MAX))];
int Primes[3432];
void sieve()
{
    vector<bool> siev(MAX,true);
    int k=0;
  
    for(int i=2;i*i<MAX;i++)
    {
        if(siev[i])
        { 
            for(int j=i*i;j<MAX;j+=i)
            {
                siev[j]=false;
            }
        }
    }

    for(int i=2;i<MAX;i++)
    { 
        if(siev[i])
        {
            Primes[k++]=i;
           // cout<<i<<" ";
            
        }
    }

}
int main()
{
    int n,m;
    int z,flag;
    sieve();
    for(int j=0;j<=100;j++)
       cout<<Primes[j]<<", ";
    int t,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        if(m==1)
            m++;
        for(int j=m;j<=n;j++)
        {
           flag=0;
           temp=(int)sqrt(j);
           for(int i=0;Primes[i]<=temp;i++)
           {
               if(j%Primes[i] == 0)
               {
                   flag=1;
                   break;
               }

           }
           if(flag == 0)
               printf("%d\n",j);
        
        }
        
              
    }
    return 0;
}


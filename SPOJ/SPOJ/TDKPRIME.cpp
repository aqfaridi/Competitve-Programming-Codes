/**
 * SPOJ Problem Set (classical)
 * 6470. Finding the Kth Prime
 * Problem code: TDKPRIME
 *
 * The problem statement is really simple. There are some queries. You
 * are to give the answers.
 * Input
 *
 * An integer stating the number of queries Q(equal to 50000), and Q
 * lines follow, each containing one integer K between 1 and 5000000
 * inclusive.
 * Output
 *
 * Q lines with the answer of each query: the Kth prime number.
 * Example
 *
 * Input:
 * 8
 * 1
 * 10
 * 100
 * 1000
 * 10000
 * 100000
 * 1000000
 *
 * Output:
 * 2
 * 29
 * 541
 * 7919
 * 104729
 * 1299709
 * 15485863
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
    int t,n;
    opt_sieve();
    for(int i=0;i<30;i++)
      cout<<p[i]*p[i]*p[i]<<",";
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",p[n]);

    }
    return 0;
}


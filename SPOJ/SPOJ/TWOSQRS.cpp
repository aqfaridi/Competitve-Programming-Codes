/**
 * SPOJ Problem Set (classical)
 * 91. Two squares or not two squares
 * Problem code: TWOSQRS
 *
 * Given integer n decide if it is possible to represent it as a sum
 * of two squares of integers.
 * Input
 *
 * First line of input contains one integer c<=100 - number of test
 * cases. Then c lines follow, each of them consisting of exactly one
 * integer 0<=n<=10^12.
 * Output
 *
 * For each test case output Yes if it is possible to represent given
 * number as a sum of two squares and No if it is not possible.
 * Example
 *
 * Input:
 * 10
 * 1
 * 2
 * 7
 * 14
 * 49
 * 9
 * 17
 * 76
 * 2888
 * 27
 *
 * Output:
 * Yes
 * Yes
 * No
 * No
 * Yes
 * Yes
 * Yes
 * No
 * Yes
 * No
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define Lim 1000020
#define sqrtLim 1000
#define Num 78500
using namespace std;
vector<bool> b((Lim-3)>>1);
vector<int> p(Num);
void opt_sieve()
{
    int cnt=2;
    for(int i=3;i<=sqrtLim;i+=2)
    {
        if(!b[(i-3)>>1])
        {
            for(int j=i*i;j<=Lim;j+=i)
            {
                if((j&1)) //odd multiple
                    b[(j-3)>>1]=true;
            }

        }
    }
    p[1]=2;    
    for(int i=0;cnt<Num;i++)
    {
        if(!b[i])
            p[cnt++]=2*i+3;
    }

}
bool prime_factorize(long long int n)
{
    int count;
    bool isNum=true;
    for(int i=1; p[i]*p[i] <= n ;i++)
    {
        if(n%p[i] == 0)
        {
            count=0;
            while(n%p[i] == 0)
            {
                count++;
                n/=p[i];
            }
            if(( (p[i]%4) == 3 ) and (count%2==1)) 
            { isNum=false;break;}
        }
    }
    if(n>1)
    {
        if((n%4)==3)  //already odd power i.e 1
            isNum=false;
    }

    return isNum;

}
int main()
{
    opt_sieve();
    int t;
    long long int n;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        //scanf("%lld",&n);
        for(long long int i=0;i<=1000000000;i++)
        {
        b=prime_factorize(i);
        if(b)
            printf("Yes ");
        else 
            printf("No ");
        }
    }
    return 0;
}


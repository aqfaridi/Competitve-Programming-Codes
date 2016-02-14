#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAX 10000
int lucky[MAX];

/**
 * int prime[101];
int lucky[MAX];
int sieve()
{
    int q=0;

    for(int i=2;i*i<=MAX;i++)
    {
        if(arry[i]==0)
            for(int j=i*i;j<=MAX;j+=i)
                arry[j]=1;
    }
    for(int i=2;i<MAX;i++)
    {
        if(arry[i]==0)
            prime[q++]=i;
    }
    return q;    
}
*/
int gen_lucky()
{
    int k=30,z=1,count,temp;
    for(int p=k;p<=4000;p++)
    {
        count=0;
        temp=p;
        for(int i=2;i*i<=temp;i++)
        {
            if(temp % i == 0)
                count++;
            while(temp % i == 0)
                temp/=i;

            if(count == 3)
            {lucky[z++]=p;break;}     
        }
        if(temp > 1 && count==2)
            lucky[z++]=p;

    }        
    return z;   
}

int main()
{
        
   // sieve();
    gen_lucky();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",lucky[n]);
    }
    return 0;
}

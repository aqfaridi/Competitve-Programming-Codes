#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long int t,n,i,j,k,n1,n2,n3;
    long long sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=n-1;i>=0;i--)
        {
            if(i%5==0)
                break;
        }
        for(j=n-1;j>=0;j--)
        {
            if(j%3==0)
                break;
        }
        for(k=n-1;k>=0;k--)
        {
            if(k%3==0 && k%5==0)
                break;
        }

        n1=j/3;
        n2=i/5;
        n3=k/15;

        sum = n1*(2*3 + (n1-1)*3)/2 + n2*(2*5 + (n2-1)*5)/2 ; //common multiples added twice

        sum = sum - n3*(2*15 + (n3-1)*15)/2;
        printf("%lld\n",sum);


    }
    return 0;
}


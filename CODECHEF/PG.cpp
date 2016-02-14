#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[1001];
int main()
{
    int t;
    long long int a,b,l,pwr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %lld",str,&b);
        l=strlen(str);

        a=str[l-1]-'0';//last digit of a

        if(b==0)
            {printf("1\n");continue;}

        b=(b%100)%4;

        if(b==0)  //for 2^4 =16 (last digit not 1)
            b=4;

        pwr=(long long int)pow(a,b);
        printf("%lld\n",pwr%10);
    }
    return 0;
}


#include<iostream>
#include<cstdio>
#define MAX 1000001
using namespace std;
unsigned long long int arry[MAX]={0,1,2,3,4,5,6,7,8,9,10,11};
 
void in()
{
    for(long int p=12;p<=MAX-1;p++)
    {
        arry[p]=(arry[p/2]+arry[p/3]+arry[p/4]);
         
    }
}
 
long long int coin(long int a)
{
    if(a<=MAX-1)
        return arry[a];
    else
        return coin(a/2)+coin(a/3)+coin(a/4);
}
 
int main()
{  
    in();
    long long int t;
    while(scanf("%lld",&t)!=EOF)
    {
        t=coin(t);
        printf("%lld\n",t);
    }
    return 0;
}



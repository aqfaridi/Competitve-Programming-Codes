#include<stdio.h>
long long mod=1000000007;
long long pow(long long n,long long exp)
{
    long long prod=1;
    while(exp>0)
    {
        if((exp&1)!=0)
            prod =(prod*n)%mod;
        n=(n*n)%mod;
        exp>>=1;
    }
    return prod;
}
int main()
{   
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long r,n,ex;
        scanf("%lld",&n);
        if(n%2==0)
            ex=0;
        else
            ex=pow(26,(n+1)/2);
        r=(((2*(pow(26,n/2+1)-26+mod)%mod)%mod)*pow(25,mod-2))%mod;
        r=(r+ex)%mod;
        printf("%lld\n",r);
         
    }
    return 0;
}

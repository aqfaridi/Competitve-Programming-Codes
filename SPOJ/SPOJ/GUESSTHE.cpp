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
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}
int main()
{
    string str;
    long long  res,k,l;
    bool b;
    long long push[50];
    while(1)
    {
        cin>>str;
        k = 0;b=true;
        if(str[0]=='*')
            break;
        res = 1LL;//every number is divisible by 1
        l = str.length();        
        for(long long i=0;i<l;i++)
        {
            if(str[i]=='Y')
                res = lcm(res,i+1);
            else if(str[i]=='N')
                push[k++] = i+1;
        }
        for(long long i=0;i<k;i++)
        {
            if(res % push[i] == 0)
            {
                b = false;
                break;
            }
        }

        if(b)
            printf("%lld\n",res);
        else
            printf("-1\n");
    }
    return 0;
}


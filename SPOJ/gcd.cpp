#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
  
    while(b!=0)
    {
        a = b;
        b = a%b;
    }
    return a;
}
int main()
{
    int t;
    long long a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        cout<<b<<endl;
        cout<< gcd(a,b)<<endl;
    }
    return 0;
}


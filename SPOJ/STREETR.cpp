#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
int input[MAX];
int diff[MAX];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&input[i]);
    for(int i=0;i<n-1;i++)
    {
        diff[i] = input[i+1]-input[i];
      //  cout<<diff[i]<<" ";
    }
    int a=diff[0];
    for(int i=1;i<n-1;i++)
    {
        a = gcd(a,diff[i]);
    }
   // cout<<a<<endl;
    long long int sum = 0;
    for(int i=0;i<n-1;i++)
    {
        sum += ((diff[i]/a)-1) ;
    }
    printf("%lld\n",sum);

    return 0;
}


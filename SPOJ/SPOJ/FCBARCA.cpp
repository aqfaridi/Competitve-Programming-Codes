#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std;
int main()
{
    long long arr[11][1001];
    int t,n,k;
    for(int k=1;k<=10;k++)
    {
        arr[k][2]=k;
        arr[k][3]=k*(k-1);
        for(int i=4;i<=1000;i++)
            arr[k][i] = (((k-1)*arr[k][i-1])%MOD + (k*arr[k][i-2])%MOD)%MOD ;
    
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("%lld\n",arr[k][n]);    
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100020
using namespace std;
long long  arr[MAX];

int main()
{

    int t,cases=0;
    long long X,n,total;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%lld %lld",&X,&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n);

        total=0;

        for(int i=0;i<n-1;i++)
        {  

            long long *location = lower_bound(arr+i+1,arr+n,X-arr[i]);
            long long index = location - arr;

            if(arr[index]== (X-arr[i]))
            {

                long long *loc=upper_bound(arr+index+1,arr+n,arr[index]);
                long long iindex=loc-arr;

                total += (iindex-index); 
            }


        }
        printf("%d. %lld\n",cases,total);
    }
    return 0;
}




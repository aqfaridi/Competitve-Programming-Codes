#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
int arr[MAX];
int main()
{
    int t,n,cases=0;
    long long sum;
   // ios::sync_with_stdio(false);
    scanf("%d",&t);    
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        for(int i=0;i<n;i++)        
            scanf("%d",&arr[i]);

        /*** base case***/
        long long  taken = arr[0];
        long long  nottaken = 0;
        for(int i=1;i<n;i++)
        {
            long long maxx = max(taken,nottaken);
            taken = (nottaken+arr[i]);
            nottaken = maxx;
        }
        
        sum = max(taken,nottaken);
        printf("Case %d: %lld\n",cases,sum);
        
    }
    return 0;
}


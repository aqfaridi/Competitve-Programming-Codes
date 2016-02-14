#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;
int arr[MAX];
int main()
{
    int t;
    int n,m,count;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(binary_search(arr+i+1,arr+n,m-arr[i]))
                count++;
        }
        printf("%d\n",count);

    }

    return 0;
}

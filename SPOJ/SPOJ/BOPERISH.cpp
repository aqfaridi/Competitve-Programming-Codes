#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100000
using namespace std;
int arr[MAX];
int main()
{
    int n,mid,low,high;
    
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        sort(arr,arr+n);
/*
        low=0;high=n-1;
        while(low<=high)
        {
            //cout<<"hello";
            mid=(low+high)/2;
            if(arr[mid]==(n-mid) || arr[mid]==(n-mid-1))
            { printf("%d\n",arr[mid]);break;}
            else if(arr[mid]>(n-mid))
                high=mid-1;
            else
                low=mid+1;

        }
*/
        int i;
        for(i=n-1;i>=0;i--)
            if(arr[i]<(n-i))
                break;
        printf("%d\n",n-i);




    }
    return 0;
}


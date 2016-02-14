#include <iostream>
#include <cstdio>
using namespace std;
int arr[110];
int main()
{
    int t,n,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=1)
                count++;
            else
                break;
        }
        printf("%d\n",count);
    }
    return 0;
}

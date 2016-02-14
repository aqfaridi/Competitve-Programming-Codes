#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
int a[MAX];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        int i=0;
        next_permutation(a,a+n);
        while( i < (n-1))
        {
            if(a[i] <= a[i+1])
                i++;
            else
                break;
        }
        if(i == (n-1))
            printf("-1");
        else
        {
            for(int i=0;i<n;i++)
                printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}


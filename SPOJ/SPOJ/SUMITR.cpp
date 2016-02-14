#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 110
using namespace std;
int main()
{
    int t,n;
    int arr[MAX][MAX];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
                scanf("%d",&arr[i][j]);
        }
     
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                arr[i][j] =  arr[i][j] + max(arr[i+1][j],arr[i+1][j+1]);
            }
        }
        printf("%d\n",arr[0][0]);
    }
    return 0;
}


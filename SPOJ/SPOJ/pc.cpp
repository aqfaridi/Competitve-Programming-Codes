#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    int t,n,count;
    int arr[110][2];    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);

    }
    count=0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            if(arr[j][0]>0 && arr[j][1]>0)
            {
            if(arr[j][0]>=arr[i][0] && arr[j][1] <=arr[i][1])
            {
                arr[j][0]=-1;arr[j][1]=-1;
                count++;
            }}
        }
    }
    printf("%d\n",count);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main() 
{
    int arr[10],diff[10],ans;
 
    for(int i=0;i<10;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<10;i++)
        arr[i] += arr[i-1];
    for(int i=0;i<10;i++)
        diff[i] = abs(100-arr[i]);
    int minn = diff[0];

    for(int i=0;i<10;i++)
    {
        if(diff[i] <= minn)
        {
            minn = diff[i];
            ans = arr[i];//cummulative
        }
    }
    printf("%d\n",ans);
    return 0;
}


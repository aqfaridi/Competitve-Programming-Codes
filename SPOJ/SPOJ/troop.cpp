#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int arr[25][5];

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=3;j++)
            {

                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            arr[i][0]=INT_MAX;
            arr[i][4]=INT_MAX;
        }
            
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                arr[i][j] += min(arr[i-1][j-1],arr[i-1][j+1]);
            }
        }
        sort(arr[n-1] +1 ,arr[n-1] + 4);
        
        printf("%d\n",arr[n-1][1]);



    }

    return 0;
}

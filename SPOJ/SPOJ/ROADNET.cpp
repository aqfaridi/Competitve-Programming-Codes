#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[210][210];
int main()
{
    int t,n;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]);

        for(int i=0;i<n;i++) //upper triangular matrix
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    b=true;
                    if(k==i || k==j)
                        continue;
                    else
                    {
                        if(arr[i][k] + arr[k][j] == arr[i][j])
                        {   b=false;break;}

                    }
                    if(b)
                        printf("%d %d\n",i+1,j+1);
                }
            }
        }


    }
    return 0;
}

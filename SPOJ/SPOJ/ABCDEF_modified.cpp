#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 110
using namespace std;
int a[MAX];
int v1[MAX*MAX*MAX];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)        
        scanf("%d",&a[i]);
    int kk=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[i])
                    v1[kk++] = a[i]*(a[j]+a[k]);  
            }
        }

    }
    sort(v1,v1 + kk);
    int val,count = 0;  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                val = (a[i]*a[j]+a[k]);
                count += (upper_bound(v1,v1+kk,val) - lower_bound(v1,v1+kk,val)) ;
            }
        }

    }
    
    printf("%d\n",count);

    return 0;
}


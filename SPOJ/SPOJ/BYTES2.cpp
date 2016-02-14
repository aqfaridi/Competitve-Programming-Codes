#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 110
using namespace std;
int a[MAX],b[MAX];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i],&b[i]);

        sort(a,a+n);
        sort(b,b+n);
        long long int count=0,maxx=0;
        for(int i=0,j=0;i<n && j<n;)
        {
            if(a[i]<b[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            maxx = max(maxx,count);
        }
        printf("%d\n",maxx);

    }

    return 0;
}


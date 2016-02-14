#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,loop,l;
    char str[30];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        scanf("%d",&loop);
        l = strlen(str);
    for(int x=0;x<loop;x++)
    {
        for(int i=l-1;i>=1;i--)
        {
            if(str[i] > str[i-1])
            {
                sort(str+i,str+l);  // to apply upper bound
                swap(str[i-1],*upper_bound(str+i,str+l,str[i-1])); // swap with just next number higher than arr[i-1]
                sort(str+i,str+l);
                break;
            }
        }
    }
    printf("%s\n",str);
    }
    return 0;
}


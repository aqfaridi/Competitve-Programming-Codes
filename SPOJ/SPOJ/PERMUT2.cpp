#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
int main()
{
    int n;
    bool b;
    int arr[MAX],pos[MAX];
    while(1)
    {
        b = false;
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            pos[arr[i]] = i;
        }
        for(int i=1;i<=n;i++)
        {
            if(pos[i] != arr[i])
            {
                b = true;
                break;
            }
        }
        if(b)
            printf("not ambiguous\n");
        else
            printf("ambiguous\n");
    }
    return 0;
}


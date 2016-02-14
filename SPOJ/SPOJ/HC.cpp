#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 100010
using namespace std;
int main()
{
    int t,n,count;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        count = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            if(str.compare("lxh")==0)
                count++;
        }
        if(!(count&1))
            printf("hhb\n");
        else
            printf("lxh\n");
    }

    return 0;
}


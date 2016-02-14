#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,count;
    
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        count=0;
        
        for(int k=0;k<=(int)sqrt(n);k++)
        {
            for(int j=k;j<=(int)sqrt(n);j++)
            {
                for(int i=j;i<=n/2;i++)
                {
                    if(i*j+ j*k + i*k == n) //ab+bc+ca ==n
                    {
                        count++;
                        break;
                    }
                    else if(i*j + j*k +i*k > n)
                        break;
                }
            }
        }
        count++;
        printf("%d\n",count);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
using namespace std;
int main()    
{
    int t,n,cases=0;
    char str[81];
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        scanf("%s",str);
        printf("%d ",cases);
        for(int i=0 ; str[i] != '\0' ;i++)
        {
            if(i==n-1)
                continue;
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

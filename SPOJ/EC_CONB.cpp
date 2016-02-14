#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int var;
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&var);
        if((var&1))
            printf("%d\n",var);
        else
        {
            temp  = 0;
            for(int i=0;i<32;i++)
            {
                if(var & (1<<i))
                    temp |= (1<<(31-i));
            }
            while(!(temp&1))
                temp>>=1;
            printf("%d\n",temp);
        }

    }
    return  0;
}

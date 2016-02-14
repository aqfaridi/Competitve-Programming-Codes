#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
int input[MAX];
int main()
{
    int t,n;
    long long sum ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&input[i]);
        sum = 0;
        sum = input[1];
        for(int i=2;i<=n;i++)        
        {
            
            sum += input[i];
            
        }

    }
    return 0;
}


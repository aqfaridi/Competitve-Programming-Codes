#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
char str[MAX];
char real[MAX],pattern1[MAX],pattern2[MAX];
int main()
{
    int l,cnt1,cnt2;
    for(int i=0;i<MAX-1;i+=2)
    {
        pattern1[i+1] = 's';
        pattern1[i] = 'c';
        pattern2[i+1] = 'c';
        pattern2[i] = 's';
    }
    while(scanf("%s",str) != EOF)
    {
        cnt1 = cnt2 = 0;
        l = strlen(str);
        for(int i=0;i<l;i++)
        {
            if(str[i] >= 65 && str[i] <= 90)
                real[i] = 'c';
            else
                real[i] = 's';
        }
    
        //finding number of  diff bits 
        //we can exchange bits := not interchange  
        //either 0 to 1 or 1 to 0
        for(int i=0;i<l;i++)
        {
            if(real[i] != pattern1[i])
                cnt1++;
            else if(real[i] != pattern2[i])
                cnt2++;
        }
        printf("%d\n",min(cnt1,cnt2));
    }
    return 0;
}


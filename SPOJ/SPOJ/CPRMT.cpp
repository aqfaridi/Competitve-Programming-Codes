#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1010
using namespace std;
char str1[MAX],str2[MAX];

int main()
{
    int m,n,k;
    while( scanf("%s\n%s",str1,str2) != EOF)
    {
        char str3[MAX];
        k=0;
        m = strlen(str1);
        n = strlen(str2);
        bool strm[m],strn[n];
        for(int i=0;i<m;i++)
            strm[i] = 1;
        for(int j=0;j<n;j++)
            strn[j] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((str1[i] == str2[j]) && strm[i] && strn[j])
                {
                    str3[k++] = str1[i] ;
                    strm[i] = 0;strn[j] = 0;
                }
            }
        }
        str3[k]='\0';
        sort(str3,str3+k);
        printf("%s\n",str3);
    }
    return 0;
}


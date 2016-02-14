#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 70
using namespace std;
char str1[MAX],str2[MAX];
int LCS[MAX][MAX];
void lcs(int m,int n)
{
    for(int i=0;i<m;i++)//row
        LCS[i][0] = 0;
    for(int j=0;j<n;j++)//col
        LCS[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i] == str2[j])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
}

int main()
{
    int m,n;
    scanf("%s",str1+1);
    scanf("%s",str2+1);
    m = strlen(str1+1);
    n = strlen(str2+1);
    lcs(m,n);
    cout<<LCS[m][n]<<endl;
    return 0;
}


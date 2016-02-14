#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 6110
using namespace std;
char str1[MAX],str2[MAX];
int LCS[MAX][MAX];
int lcsub(int m,int n)
{
    int maxx = 0;
    for(int i=0;i<m;i++)//row
        LCS[i][0] = 0;
    for(int j=0;j<n;j++)//col
        LCS[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i] == str2[j])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                maxx = max(maxx,LCS[i][j]);
            }
            else
                LCS[i][j] = 0;
        }
    }
    return maxx;
}

int main()
{
    int t,m,maxx;
    ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str1+1);
        m = strlen(str1+1);
        for(int i=1;i<=m;i++)
            str2[i] = str1[m+1-i];
        maxx = lcsub(m,m);
        cout<<m-maxx<<endl;
    }
    return 0;
}


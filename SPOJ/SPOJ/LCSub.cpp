#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 6110
using namespace std;
char str1[MAX],str2[MAX];
int LCS[MAX][MAX];
vector<char> v;
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
                v.push_back(str1[i]);
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
    int t,m,n,maxx,nos,x;
    ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--)
    {
        maxx = 0;
        scanf("%d",&nos);
        scanf("%s",str1+1);
        m = strlen(str1+1);
        for(int i=1;i<nos;i++)
        {
            v.clear();
            scanf("%s",str2+1);
            n = strlen(str2+1);       
            maxx = max(maxx,lcsub(m,n));
            for(x=0;x<v.size();x++)
            {
                cout<<v[i]<<" ";
                str1[x+1] = v[x];
            }
            str1[x]='\0';
            m =  strlen(str1);
        }
        cout<<maxx<<endl;
    }

    return 0;
}


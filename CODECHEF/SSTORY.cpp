#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 500010
#define rep(i,n) for(int i=0;i<n;i++)
int n,gap;
int sa[MAX],pos[MAX],tmp[MAX],lcp[MAX];
char str[MAX];
bool cmp(int i,int j)
{
    if(pos[i] != pos[j])
        return pos[i]<pos[j];
    i+=gap;j+=gap;
    return (i<n && j<n) ? pos[i]<pos[j] : i>j;
}
void buildSA()
{
    n = strlen(str);
    rep(i,n)    sa[i] = i , pos[i] = str[i];
    for(gap = 1;;gap*=2)
    {
        sort(sa,sa+n,cmp);
        rep(i,n-1)  
            tmp[i+1] = tmp[i] + cmp(sa[i],sa[i+1]);
        rep(i,n)
            pos[sa[i]] = tmp[i];
        if(tmp[n-1] == n-1) break;
    }
}
int maxx = -1;
void buildLCP()
{
    for(int i=0,k=0 ; i<n ; i++)
    {
        if(pos[i] != n-1)
        {
            for(int j = sa[ (pos[i]+1) ] ; str[i+k] == str[j+k];)
            {
                ++k;
            }
            lcp[pos[i]] = k;
            if(k) 
                --k;
        }        
    }
}
int main()
{
    int idx;
    char str1[MAX],str2[MAX];
    scanf("%s",str1);
    scanf("%s",str2);
    strcpy(str,str1);
    int l = strlen(str1);
    str[l] = '$';
    strcat(str,str2);
    buildSA();
    buildLCP();
    maxx = 0;
    for(int i=0;i<n;i++)
    {
        if(sa[i]>l && sa[i+1]<l)
        {
            if(lcp[i] > maxx)
            {
                maxx = lcp[i];
                idx = sa[i];
            }
            else if((lcp[i] == maxx) && sa[i] < idx)
                 idx = sa[i];
        }
        else if(sa[i]<l && sa[i+1]>l)
        {
            if(lcp[i] > maxx)
            {
                maxx = lcp[i];
                idx = sa[i+1];
            }
            else if((lcp[i] == maxx) && sa[i+1] < idx)
                 idx = sa[i+1];
        }
    }
    if(maxx == 0)
    {
        printf("0\n");
        return 0;
    }

    for(int i=idx;i<(idx+maxx);i++)
        printf("%c",str[i]);
    printf("\n");
    printf("%d\n",maxx);
    return 0;
}



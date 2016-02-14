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

#define MAX 2500010
#define rep(i,n) for(int i=0;i<n;i++)
int n,gap;
int sa[MAX],pos[MAX],tmp[MAX],lcp[MAX];
char str[2*MAX];
bool cmp(int i,int j)
{
    if(pos[i] != pos[j])
        return pos[i]<pos[j];
    i+=gap;j+=gap;
    return (i<n && j<n) ? pos[i]<pos[j] : i>j;//if ith pos reached end then return 1(i>j) since ith is smaller
}
void buildSA()
{
    n = strlen(str);
    rep(i,n)    sa[i] = i , pos[i] = str[i];//ascii value in pos first time
    for(gap = 1;;gap*=2)
    {
        sort(sa,sa+n,cmp);
        rep(i,n-1)  
            tmp[i+1] = tmp[i] + cmp(sa[i],sa[i+1]);//lexo. names acc. to pos(prev)::increment by 1 when diff occurs
        rep(i,n)
            pos[sa[i]] = tmp[i];//pos updated by rank
    
        //terminating condition
        if(tmp[n-1] == n-1) break;//all rank assigned no further changes in tmp
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
    char str1[MAX],str2[MAX];
    scanf("%s",str1);
    scanf("%s",str2);
    strcpy(str,str1);
    int l = strlen(str1);
    str[l] = '$';
    strcat(str,str2);
    buildSA();
    buildLCP();
    maxx = -1;
    for(int i=0;i<n;i++)
    {
        if((sa[i]<l && sa[i+1]>l) || (sa[i]>l && sa[i+1]<l))
            maxx = max(maxx,lcp[i]);                    
    }
    printf("%d\n",maxx);
    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define MAX 30001
using namespace std;
char word[21];
int tree[MAX];
long long cnt=0LL;
map<string,int> m;
void update(int idx)
{
    while(idx<MAX)
    {
        tree[idx]++;
        idx += (idx & -idx);
    }
}
void read(int idx)
{
    while(idx>0)
    {
        cnt += tree[idx];
        idx -= (idx & -idx);
    }
}
int main()
{
    int t,n,num;
    scanf("%d",&t);
    while(t--)
    {
        cnt = 0LL;
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=n;i>0;i--)
        {
            scanf("%s",word);
            m[word] = i;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",word);
            num = m[word];
            read(num);
            update(num);
        }
        printf("%lld\n",cnt);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 200010
using namespace std;
int tree[MAX];
void update(int val)
{
    int idx = val;
    while(idx && idx<MAX)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
long long query(int idx)
{
    long long sum = 0LL ;
    idx--;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    int t,n,num;
    long long count;
    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        count = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            count += query(num);
            update(num);
        }
        printf("%lld\n",count);
    }


    return 0;
}


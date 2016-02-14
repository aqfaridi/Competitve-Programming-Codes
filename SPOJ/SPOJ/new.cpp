#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100010
using namespace std;
char str[MAX];
struct data
{
    int cnt;
    char lvalue,rvalue;
};
data tree[MAX<<2];
data make_data(char val)
{
    data res;
    res.cnt = 0;
    res.lvalue = val;
    res.rvalue = val;
    return res;
}
data combine_data(data l,data r)
{
    data res;
    if(l.rvalue==r.lvalue)
        res.cnt = l.cnt + r.cnt + 1;
    else
        res.cnt = l.cnt + r.cnt ;
    return res;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = make_data(str[b]);
        return ;
    }
    int mid = (b+e)/2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    tree[node] = combine_data(tree[2*node],tree[2*node+1]);
}
data query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)/2;
    if(j<=mid)
        return query(2*node,b,mid,i,j);
    if(i>mid)
        return query(2*node+1,mid+1,e,i,j);

    return combine_data(query(2*node,b,mid,i,j),query(2*node+1,mid+1,e,i,j));

}

int main()
{
    int t,n,q;
    int ii,jj;
    scanf("%s",str+1);
    n = strlen(str+1);

    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&ii,&jj);
        data d = query(1,1,n,ii,jj);
        printf("%d\n",d.cnt);
    }

    return 0;
}

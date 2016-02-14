#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
int input[MAX];
struct data
{
    int lfreq,rfreq,maxfreq;
};
data tree[MAX<<2];
data make_data(int val)
{
    data res;
    res.lfreq = res.rfreq = res.maxfreq = 1;
    return res;
}
data combine(int b,int e,data l,data r)
{
    int mid = (b+e)/2;
    data res;
    if(input[mid]==input[mid+1])
    {
        res.lfreq = l.lfreq + r.lfreq*(input[b]==input[mid]);
        //using the fact that numbers are given in increasing order
        res.rfreq = r.rfreq + l.rfreq*(input[mid+1]==input[e]);
        int temp = l.rfreq + r.lfreq;
        res.maxfreq = max(temp,max(l.maxfreq,r.maxfreq));
    }
    else
    {
        res.lfreq = l.lfreq;
        res.rfreq = r.rfreq;
        res.maxfreq = max(l.maxfreq,r.maxfreq);
    }
    return res;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = make_data(input[b]);
        return ;
    }
    int mid = (b+e)/2;
    build(node<<1,b,mid);
    build((node<<1)+1,mid+1,e);
    tree[node] = combine(b,e,tree[node<<1],tree[(node<<1)+1]);
}
data query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)//in range
    {
        return tree[node];
    }
    //no specific datastructure to return ??if()//out of range
    //So going in range with the help of mid
    int mid = (b+e)/2;
    if(j<=mid)
        return query(node<<1,b,mid,i,j);
    if(i>mid)//can go to both sides
        return query((node<<1)+1,mid+1,e,i,j);
    /******** out of range condition finished*********/
    data p1 = query(node<<1,b,mid,i,j);
    data p2 = query((node<<1)+1,mid+1,e,i,j);
    return combine(b,e,p1,p2);
}
int main()
{
    int N,Q,x,y;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
            break;
        scanf("%d",&Q);
        for(int i=1;i<=N;i++)
            scanf("%d",&input[i]);
        build(1,1,N);
        for(int i=0;i<Q;i++)
        {
            scanf("%d %d",&x,&y);
            data result = query(1,1,N,x,y);
            printf("%d\n",result.maxfreq);
        }     
               
    }
    return 0;
}


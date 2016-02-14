#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 50010
using namespace std;
int input[MAX];
struct data
{
    int sum,Lmax,Rmax,maxv;
};
data tree[3*MAX];
data combine(data left,data right)
{
    data res;
    res.sum = left.sum + right.sum;
    res.Lmax = max(left.Lmax,left.sum + right.Lmax);
    res.Rmax = max(right.Rmax,right.sum + left.Rmax);
    res.maxv = max(max(left.maxv,right.maxv),left.Rmax+right.Lmax);
    return res;
}
data make_data(int val)
{
    data res;
    //res.Lmax = res.Rmax = res.maxv = max(0,val);//for getting 0 ans when all numbers are negative
    //res.sum = val;
    res.Lmax = res.Rmax = res.maxv = res.sum = val;
    return res;
}
void init_tree(int node,int b,int e)
{
    if(b==e) // leaf node
    {
        tree[node] = make_data(input[b]);
        return ;
    }
    int mid = (b+e)/2;
    init_tree(2*node,b,mid);
    init_tree(2*node+1,mid+1,e);
    tree[node] = combine(tree[2*node],tree[2*node+1]);
}
void update(int node,int b,int e,int index,int newval)
{
    if(b==e)
    {
        tree[node] = make_data(newval);
        return ;
    }

    int mid = (b+e)/2;
    // go to left or right child acc to mid in the search of
    // indexleafnode
    if(index<=mid)
        update(2*node,b,mid,index,newval);
    else
        update(2*node+1,mid+1,e,index,newval);

    tree[node] = combine(tree[2*node],tree[2*node+1]);
}
data query(int node,int b,int e,int i,int j)    
{
    if(b>=i &&  e<=j)//in range   
        return tree[node];
    
    //out of range ?? what to return( 0 , INT_MIN  nothing ) ?? 
    //not sure,  So go to left or right child acc to mid
    int mid = (b+e)/2;
    if(j<=mid)
        return query(2*node,b,mid,i,j);
    if(i>mid)//not else if ?? can go to both sides
        return query(2*node+1,mid+1,e,i,j);
    /***********out of range condition finished**********/
    data p1 = query(2*node,b,mid,i,j);
    data p2 = query(2*node+1,mid+1,e,i,j);
    
    return combine(p1,p2);
}
int main()
{
    int N,q,x,y,c;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&input[i]);
    scanf("%d",&q);
    init_tree(1,1,N);
    /**
    for(int i=1;i<2*N;i++)
        cout<<tree[i].sum<<" ";
    cout<<endl;
    **/
    
    for(int i=0;i<q;i++)
    {
        scanf("%d %d %d",&c,&x,&y);
        if(c)
        {
            data result = query(1,1,N,x,y);
            printf("%d\n",result.maxv);
        }
        else
            update(1,1,N,x,y);
    }

    return 0;
}


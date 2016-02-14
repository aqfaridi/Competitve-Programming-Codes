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
    int fmax,smax;
};
data tree[MAX<<2];
data make_data(int val)
{
    data res;
    res.fmax = val;
    res.smax = 0;
    return res;
}
data combine_data(data l,data r)
{
    data res;
    if(l.smax > r.fmax)
    {res.fmax = l.fmax ; res.smax = l.smax;}
    else if(l.fmax > r.fmax)
    {res.fmax = l.fmax ; res.smax = r.fmax;}
    else if(r.smax > l.fmax)
    {res.fmax = r.fmax ; res.smax = r.smax;}
    else 
    {res.fmax = r.fmax ; res.smax = l.fmax;}
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
void update(int node,int b,int e,int index,int val)
{
    if(b==e)
    {
        tree[node] = make_data(val);
        return ;
    }
    int mid = (b+e)/2;
    if(index <= mid)
        update(2*node,b,mid,index,val);
    else
        update(2*node+1,mid+1,e,index,val);

    tree[node] = combine_data(tree[2*node],tree[2*node+1]);

}
int main()
{
    int N,q,x,y;
    int ind,nval;
    char ch;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&input[i]);

    build(1,1,N);
    /**
    for(int i=1;i<2*N;i++)
    {
        cout<<tree[i].fmax<<" "<<tree[i].smax<<endl;
    }**/
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        cin>>ch;        
        if(ch=='Q')
        {
            scanf("%d %d",&x,&y);
            data result = query(1,1,N,x,y);
            long long sum = result.fmax + (long long)result.smax ;
            printf("%lld\n",sum);
        }
        else if(ch == 'U')
        {
            //cout<<ch<<endl;

            scanf("%d %d",&ind,&nval);
            //cout<<x<<" "<<y<<endl;
            update(1,1,N,ind,nval);
            //cout<<"updated";
        }
        //cout<<q<<" "<<i<<endl;
    }

    return 0;
}


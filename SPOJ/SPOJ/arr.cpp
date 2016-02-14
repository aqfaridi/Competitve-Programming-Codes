#include <iostream> 
#include <cstdio> 
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
//no need for input matrix in this question
long long int sum[3*MAX],add[3*MAX],input[MAX];

void prepare(int node,int b,int e)
{
    //lazily updating the child for i) sum & ii)add
    //transfering the responsibility of add to child node
    add[2*node] += add[node];
    add[2*node+1] += add[node];

    int mid = (b+e)/2;
    sum[2*node] += (mid-b+1)*add[node];  // no of elements in left half(child) of node=(mid-b+1)
    sum[2*node+1] += (e-mid)*add[node];  // when subtracting it does not include minuend 
    add[node]=0;  // release add of node
}
void update(int node,int b,int e,int i,int j,long long int  v)
{
    if(i>e || j<b) // be ij or ij be  //out of range
        return ;
    if(b>=i && e<=j) // i be j    
    {
        //in range update directly (sum and add) matrix 
        //without going to child
        sum[node] += (e-b+1)*v;  // no. of elements in range(b,e) x value
        add[node] += v;         // flag for next update  later on
    }
    else  // not entirely in range
    {
        // then we have to go to child (2*node & 2*node+1)
        // before going to child (prepare the child for update 
        // using add matrix)
        prepare(node,b,e);
        int mid=(b+e)/2;
        update(2*node,b,mid,i,j,v);
        update(2*node+1,mid+1,e,i,j,v);
        sum[node] = sum[2*node]+sum[2*node+1]; // updating the node after updating the child
    }

}
long long int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return sum[node];
    prepare(node,b,e);//before going to child update add & sum of child
    int mid=(b+e)/2;
    return (query(2*node,b,mid,i,j) + query(2*node+1,mid+1,e,i,j));

}
void build(int node,int b,int e)
{
        if(b==e)
        {
             sum[node] = input[b];
             return ;
        }
        int mid = (b+e)/2;
        build(2*node,b,mid);
        build(2*node+1,mid+1,e);
        sum[node] = sum[2*node] + sum[2*node+1];
}
void assign(int node,int b,int e,int index,int v)
{
    if(b==e)
    {
        sum[node] = v;
        return;
    }
    int mid=(b+e)/2;
    if(index <= mid)
        assign(2*node,b,mid,index,v);
    else
        assign(2*node+1,mid+1,e,index,v);

    sum[node] = sum[2*node] + sum[2*node+1];
}
int main()
{
   
    int t,N,C,p,q,c;
    long long int v;
    t = 1;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        memset(add,0,sizeof(add));
        scanf("%d %d",&N,&C);//C:commands
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",&input[i]);
            //cin>>input[i];
        }
        build(1,1,N);     
        for(int i=0;i<C;i++)
        {
            scanf("%d",&c);
            if(c==2)
            {
                scanf("%d",&v);
                update(1,1,N,1,N,v); //lazy propagation
            }
            else if(c==1)
            {
                scanf("%d %d",&p,&q);
                assign(1,1,N,p,q);
            }
            else if(c==3)
            {
                scanf("%d",&q);
                printf("%lld\n",query(1,1,N,q,q));
            }
        }
    }
    return 0;
}




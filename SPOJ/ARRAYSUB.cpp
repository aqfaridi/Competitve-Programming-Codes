#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#define MAX 1000010
using namespace std;
int input[MAX],tree[3*MAX];
void init_tree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = input[b];
        return ;
    }
    int mid = (b+e)/2;
    init_tree(2*node+1,b,mid);
    init_tree(2*node+2,mid+1,e);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
}
int query(int node,int b,int e)
{
   return tree[node];       
}
void update(int node,int b,int e,int index,int v)
{
    if(b==e)
    {
        tree[node] = v;
        return ;
    }
    int mid=(b+e)/2;
    if(index <= mid)//go to left child
        update(2*node+1,b,mid,index,v);
    else
        update(2*node+2,mid+1,e,index,v);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
  
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&input[i]);
    scanf("%d",&k); 
    
    init_tree(0,0,k-1);  // k element tree
    /**
    for(int i=0;i<2*k;i++)
        cout<<tree[i]<<" ";
    cout<<endl;**/
    
    for(int i=0;i<n-k;i++)
    {
        printf("%d ",query(0,0,k-1));
        update(0,0,k-1,i%k,input[i+k]);
        /** 
        for(int j=0;j<2*k;j++)
            cout<<tree[j]<<" ";
        cout<<endl;**/
    }
    printf("%d",query(0,0,k-1));

    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100010
using namespace std;
int input[MAX];
int tree[3*MAX];
int mintree[3*MAX];
void buildtree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=input[b];
        return;
    }

    int mid=(b+e)/2;
    buildtree(2*node,b,mid);
    buildtree(2*node+1,mid+1,e);

    tree[node]=max(tree[2*node],tree[2*node+1]); 
}
void initmin(int node,int b,int e)
{
    if(b==e)
    {
        mintree[node]=input[b];
        return ;
    }
    int mid=(b+e)/2;
    initmin(2*node,b,mid);
    initmin(2*node+1,mid+1,e);

    mintree[node]=min(mintree[2*node],mintree[2*node+1]);
}
int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)   //in range   i b e j
    {
        return tree[node];
    }

    if(j<b || i>e)                // out of range i j be   or be i j
    {
        return INT_MIN;
    }

    if(b==e) //leaf node
        return tree[node];

    int mid=(b+e)/2;
    int p1=query(2*node,b,mid,i,j);
    int p2=query(2*node+1,mid+1,e,i,j);
    
    return max(p1,p2);    
}


int minquery(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)   //in range   i b e j
    {
        return mintree[node];
    }

    //if(j<b || i>e)                // out of range i j be   or be i j
    if((i<b && j<b) || (i>e && j>e))
    {
        return INT_MAX;
    }

    if(b==e) //leaf node
        return mintree[node];

    int mid=(b+e)/2;
    int p1=minquery(2*node,b,mid,i,j);
    int p2=minquery(2*node +1,mid+1,e,i,j);
    
    return min(p1,p2);    
}
double maxi(double a,double b)
{
    if(a>b) return a;
    else    return b;
}
int main()
{
    int n,q,qi,qj;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&input[i]);

    buildtree(1,1,n);
    initmin(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&qi,&qj);
        qi+=1;qj+=1;
        int maxx=max(query(1,1,n,1,qi-1),query(1,1,n,qj+1,n));
        //cout<<maxx<<endl;
        int minn=minquery(1,1,n,qi,qj);
        int max1=query(1,1,n,qi,qj);
        //cout<<minn<<" "<<max1<<endl;
        printf("%.1f\n",maxi(( minn + (max1-minn)/2.0 ),maxx+minn));
    }


    return 0;
}


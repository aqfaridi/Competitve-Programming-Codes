#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAX 100010
LL k;
LL hist[MAX];
struct data
{
    LL minval;
    LL index;
};
data tree[MAX << 2];

data make_data(LL val,LL idx)
{
    data res;
    res.minval = val;
    res.index  = idx;
    return res;
}
data combine_data(data l , data r)
{
    data res;
    if(l.minval <= r.minval)
    {
        res.minval = l.minval;
        res.index = l.index;
    }
    else 
    {
        res.minval = r.minval;
        res.index = r.index;
    }
    return res;
}
void init_tree(LL node,LL b,LL e)
{
    if(b==e)
    {
        tree[node] = make_data(hist[b],b);
        return ;
    }
    LL mid = b+(e-b)/2;
    init_tree(2*node,b,mid);
    init_tree(2*node+1,mid+1,e);

    tree[node] = combine_data(tree[2*node],tree[2*node+1]);
}
data query(LL node,LL b,LL e,LL i,LL j)
{
    //i b e j
    if(b>=i && e<=j)
        return tree[node];
    LL mid = b+(e-b)/2;
    if(j<=mid)
        return query(2*node,b,mid,i,j);
    if(i>mid)
        return query(2*node+1,mid+1,e,i,j);
    
    return combine_data(query(2*node,b,mid,i,j),query(2*node+1,mid+1,e,i,j));
}
LL maxArea(LL l,LL r)
{
    if(l>r)
        return INT_MIN;
    if(l==r)
        return hist[l];
    data mid = query(1,1,k,l,r);
    LL m = mid.index;
    return max( max(maxArea(l,m-1),maxArea(m+1,r)) , hist[m]*(r-l+1) );
}
int main()
{
    while(1)
    {
        scanf("%lld",&k);
        if(k==0)
            break;
        for(int i=1;i<=k;i++)
            scanf("%lld",&hist[i]);
        init_tree(1,1,k);
        //data result = query(1,1,k,1,k);
        //cout<<result.minval<<" "<<result.index<<endl;
        printf("%lld\n",maxArea(1,k));
    }
    return 0;
}



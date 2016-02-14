#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<LL> tree1,tree2;
int n;
void update(LL idx,LL val)
{
    for(LL i=idx;i<=n;i += (i & -i))
    {
        tree2[i] += val;
        tree1[i] += val*(i-idx+1);//range down till starting idx
    }
}
void update_range(LL a,LL b,LL val)
{
    update(a,val);
    update(b+1,-val);
}
LL cumm_freq(LL idx)
{
    LL sum = 0;
    for(LL i=idx;i>0;i -= (i & -i))
    {
        sum += tree1[i];
        sum += tree2[i]*(idx-i);//covering upper part of range
    }
    return sum;
}
LL get_freq(LL idx)
{
    LL sum = tree1[idx]; 
    LL z = idx - (idx & -idx); 
    idx--;
    for(LL i=idx ; idx!=z ; i -= (i & -i))
    {
        sum -= tree1[idx];
        sum -= tree2[i]*(idx-i);
    }
    for(LL i = z;i>0;i -= (i & -i))
        sum += tree2[i];
   
    return sum;
}
int main()
{
    int t,c,q;
    LL x,y,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        tree1.resize(n+1);
        tree2.resize(n+1);
        tree1.assign(n+1,0);
        tree2.assign(n+1,0);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&c);
            if(c==0)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update_range(x,y,v);
            }   
            else if(c==1)
            {
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",(cumm_freq(y) - cumm_freq(x-1))) ;
            }
        }
    }
    return 0;
}


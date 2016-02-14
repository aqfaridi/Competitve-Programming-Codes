#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <algorithm>
#define MAX 100010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int input[MAX];
int tree[3*MAX];
void build(int node,int b,int e)
{
    if(b==e)
        tree[b] = input[b];
    int mid = (b+e)/2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
}

int main()
{
    int t,n,q,c;
    t = 1;
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&input[i]);

        build(1,n);

        for(int i=0;i<q;i++)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d %d",&v,&x);
                //v is index and x is val
                update(1,n,v,x);
            }
    }
    return 0;
}


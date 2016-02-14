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
#define MAX 100010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL minn = INT_MAX;

int t,price[MAX],shop_price[MAX],num,discount[MAX],shop_disc[MAX];
int n=0,m=0;
void recursion(int pr[][m],int disc[][m],int x,int y,LL ans,int dis)
{
    if(pr[x][y] - dis >=0)
        ans += (pr[x][y] - dis);
    dis = disc[x][y];
    if(y==m)
    {
        minn = min(ans,minn);
        return ;
    }
    else
    {
        if(y<m)
        {
            recursion(pr,disc,x,y+1,ans,dis);
        }                
        if(x<n)
        {
            dis = 0;
            recursion(pr,disc,x+1,y+1,ans,dis);
        }
    }
}

void recurse(int pr[][m],int disc[][m],int x,int y,LL ans,int dis)
{
    if(pr[x][y] - dis >=0)
        ans += pr[x][y] - dis;
    dis = disc[x][y];
    if(y==m)
    {
        minn = min(ans,minn);
        return ;
    }
    else
    {
        if(y<m)
        {
            recurse(pr,disc,x,y+1,ans,dis);
        }                
        if(x>1)
        {
            dis = 0;
            recurse(pr,disc,x-1,y+1,ans,dis);
        }
    }
}
int main()
{
    //int t,price[MAX],shop_price[MAX],num,discount[MAX],shop_disc[MAX];
    scanf("%d",&t);
    while(t--)
    {
        minn = INT_MAX;
        n = 0;m = 0;
        scanf("%d %d",&n,&m);
        int pr[n+1][m+1],disc[n+1][m+1];        
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&price[j]);
            pr[1][j] = price[j];
            shop_price[j] = 1;
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&num);
                pr[i][j] = num;
                if(num < price[j])
                {
                    price[j] = num;
                    shop_price[j] = i;
                }
            }
        }
        
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&discount[j]);
            disc[1][j] = discount[j];
            shop_disc[j] = 1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&num);
                disc[i][j] = num; 
                if(num > discount[j])
                {
                    discount[j] = num;
                    shop_disc[j] = i;
                }
            }
        }
        recursion(pr,disc,1,1,0,0);
        recurse(pr,disc,2,1,0,0);
        printf("%lld\n",minn);
        /**
       LL minn=INT_MAX,ans = 0,cur_dis=0,cur_shop=1,pr_possible,dis_possible;
       
       for(int x = 1;x<=n;x++)
       {
       ans = 0;
       ans += pr[x][1];
       cur_shop = x;
       cur_dis = disc[cur_shop][1];
        
       for(int j=2;j<=m;j++)
       {              

           if((pr[cur_shop][j] - cur_dis) < price[j])
           {
                if(pr[cur_shop][j] - cur_dis >=0)
                    ans += (pr[cur_shop][j] - cur_dis);   
                //cur_shop = same
                cur_dis = disc[cur_shop][j];
           }          
           else if((pr[cur_shop][j] - cur_dis) == price[j])
           {
               if(disc[cur_shop][j] < disc[shop_price[j]][j])               
               {
                   cur_dis =  disc[shop_price[j]][j];
                   cur_shop = shop_price[j];
               }
               else
                   cur_dis = disc[cur_shop][j];
           }
           else 
           {
                ans += price[j];
                cur_shop = shop_price[j];
                cur_dis = disc[cur_shop][j];
           }
       }
       minn = min(minn,ans); 
       }
       printf("%lld\n",minn);
        **/
    }
    return 0;
}


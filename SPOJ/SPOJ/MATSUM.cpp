#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1050
using namespace std;
int tree[MAX][MAX]; // 2d array
void update(int x,int y,int val)
{
    while(x<MAX)
    {
        int idx = y;
        while(idx<MAX)
        {
            tree[x][idx] += val;
            idx += (idx & -idx);
        }
        x += (x & -x);
    }
}
int query_sum(int x,int y)
{
    int sum=0;
    while(x>0)
    {
        int idx = y;
        while(idx>0)
        {   
            sum += tree[x][idx];
            idx -= (idx & -idx);
        }
        x -= (x & -x);
    }
    return sum;
}
int main()
{
    int t,n,x,y,x1,y1,x2,y2,val,v1,v2,v3,v4,sum;
    char cmd[5];
    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree[0][0]*MAX*MAX));
        scanf("%d",&n);
        while(1)
        {
            scanf("%s",cmd);
            if(strcmp(cmd,"END") == 0)
                break;
            if(strcmp(cmd,"SUM") == 0)
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                
                /*** avoid (0,0) - not useful of binary indexing */
                v1 = query_sum(x2+1,y2+1); //I quad
                v3 = query_sum(x1,y1);  //III quad
                v2 = query_sum(x1,y2+1); //II quad
                v4 = query_sum(x2+1,y1); //IV quad
                sum = (v1+v3 - v2-v4);
                printf("%d\n",sum);
                                 
            }
            else if(strcmp(cmd,"SET") == 0)
            {
                scanf("%d %d %d",&x,&y,&val);
                //cout<<x<<" "<<y<<" "<<val<<endl; 
                /*** avoid (0,0) - not useful of binary indexing */
                v1 = query_sum(x+1,y+1); //I quad
                v3 = query_sum(x,y);  //III quad
                v2 = query_sum(x,y+1); //II quad
                v4 = query_sum(x+1,y); //IV quad
                val = val - (v1+v3 - v2-v4); //inclusion-exclusion of 2d plane
                update(x+1,y+1,val);//this value get added(can be (-)ve or (+)ve)
            }
        }
    }            
    return 0;
}


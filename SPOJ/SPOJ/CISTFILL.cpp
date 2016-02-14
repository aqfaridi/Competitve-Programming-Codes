#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 500010
using namespace std;
const double INF=300000000;
struct node
{
    double b,h,w,l;
};
node input[MAX];
int n;
double function(double LB,double mid)
{
    double volmid=0.0,h2,h1;
    for(int i=0;i<n;i++)
    {
        h1 = max(LB,input[i].b);
        h2 = min(mid,input[i].h);
        if(h2-h1 > 0.000005)
            volmid += (h2-h1)*(input[i].l)*(input[i].w);
    }
    return volmid;
}
int main()
{
    int t;
    double b,h,w,l,vol,minn=INF,maxx=-INF;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&b,&h,&w,&l);
            input[i].b = b;input[i].h = b+h;
            input[i].w = w;input[i].l = l;
            minn = min(minn,b);
            maxx = max(maxx,b+h);
        }
        double low = minn,high = maxx,mid;
        scanf("%lf",&vol);
        if(vol - function(minn,maxx) > 0)
        {
            printf("OVERFLOW\n");
            continue;
        }
        while(low - high <= 0.000005)
        {
            mid = (low+high)/2.0;
            if(vol - function(minn,mid) >= 0.000005)
            {
                //go to right
                low = mid + 0.000005;
            }
            else
            {
                //go to left
                high = mid - 0.000005;
            }
        }

        printf("%.2lf\n",mid);

    }
    return 0;
}


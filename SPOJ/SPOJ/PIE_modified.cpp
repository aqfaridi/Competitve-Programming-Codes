#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 10010
using namespace std;
int r[MAX];
int nop,nof;
double vol[MAX];
int binary(double  mid)
{
    int count = 0;
    for(int i=0;i<nop;i++)
    {
        count += floor(vol[i] / mid); 
    }
    return count;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {        
        scanf("%d %d",&nop,&nof);
        for(int i=0;i<nop;i++)
        {
            scanf("%d",&r[i]);
            vol[i] = (M_PI * r[i] * r[i]);
        }
        double mid,low = 0.0 , high = 10000000000.0;
        while(low-high < 0.0000005)
        {
            mid = (low+high)/2.0;
            if(binary(mid) >= (nof+1))
            { 
                //goto right half
                low = mid+0.0000005;
            }
            else
            {
                //goto left half
                high = mid-0.0000005;
            }
        }
        printf("%.4lf\n",mid);


    }
    return 0;
}


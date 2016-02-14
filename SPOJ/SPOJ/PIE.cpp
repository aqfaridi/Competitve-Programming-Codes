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
int binary(int mid)
{
    double svol = M_PI * mid * mid;
    int count = 0;
    for(int i=0;i<nop;i++)
    {
        count += floor(vol[i] / svol); 
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
        int mid,low = 0 , high = 10000;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(binary(mid) >= (nof+1))
            { 
                //goto right half
                low = mid+1;
            }
            else
            {
                //goto left half
                high = mid-1;
            }
        }
        cout<<mid*mid*M_PI<<endl;


    }
    return 0;
}


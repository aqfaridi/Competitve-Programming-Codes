#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
long double  a;
long double loging[2800011];
bool function(long long int mid)
{
    long double fterm,sterm;
    fterm = loging[mid];
    sterm = mid * (log10(a));

    return (fterm - sterm > 0);
}
int main()
{
    int t;
    loging[1] = 0.0;
    for(long double i=2;i<=2800010;i++)
        loging[(int)i] = loging[(int)(i-1)] + log10(i);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%Lf",&a);   
    long long ans=INT_MAX;
    long long int mid,low=0,high = 2800010;
    while(low<=high)
    {
        mid = (low+high)/2;

        long long fterm,sterm;
        fterm = loging[mid];
        sterm = mid*(log10(a));
        /**
        if( (fterm-sterm)>0.00000005 )
        {
            ans = mid ;
            break;
        }
        **/
        if( (fterm-sterm) > 0 )
        {
            //goto left 
            //for least n finding
            if(ans > mid)
                ans = mid;
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%lld\n",ans);
    }
    return 0;
}


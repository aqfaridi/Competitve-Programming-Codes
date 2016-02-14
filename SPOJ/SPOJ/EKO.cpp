#include <iostream>
#include <cstdio>
#include <climits>
#define MAX 1000010
using namespace std;
long long arr[MAX],n,m;
long long binary(long long mid)
{
    long long sum = 0LL ;
    for(long long i=0;i<n;i++)
    {
        if((arr[i] -  mid) > 0)
            sum += (arr[i]-mid);
    }
    return sum;
}
int main()
{
    long long  maxx = -1 ;
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i] > maxx)
            maxx = arr[i];
    }
    long long mid,low = 0 , high = maxx;
    //tricky
    long long height = 0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(m == binary(mid))
        {
            height = mid;
            break;
        }
        else if(m < binary(mid))// satisfied condition
        {
            low = mid + 1;
            if(mid > height) // since we have to find max height 
                height = mid; //satisfying above condition
        }
        else   
            high = mid - 1;
    }
    printf("%lld\n",height);
    return 0;
}


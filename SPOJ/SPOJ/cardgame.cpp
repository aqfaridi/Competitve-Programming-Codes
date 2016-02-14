#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;
int arr[10001],t[10001];
int sum=0;
void g(int p,int k,int q=0,int r=0)
{
        if(q==k)
                {
                      sum+=t[k-1];
                      cout<<t[k-1]<<" ";
                 }
        else
              {
                     for(int i=r;i<p;i++)
                     {
                          t[q]=arr[i];
                          g(p,k,q+1,i+1);
                     }
              }
}


int main()
{

    int t,n,k;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        sum=0;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        { scanf("%d",&arr[i]);}
        sort(arr,arr+n);
        g(n,k);
      
        printf("Case #%d: %lld\n",j,sum);
    
    
    
    }


}

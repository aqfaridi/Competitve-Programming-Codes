#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[110];
int sieve[110];
int main()
{
    int t,n,count;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sieve[i]=1;
        }
        b=true;
        while(b)
        {
            b=false;
            for(int i=0;i<n;i++)
            {
                if( (i-1)>=0 && arr[i] > arr[i-1])
                {   
                    if(sieve[i] <= sieve[i-1])
                    {
                        sieve[i] =  sieve[i-1]+1;
                        b=true;
                    }
                }
                if((i+1)<n && arr[i] > arr[i+1])
                {
                    if(sieve[i]<=sieve[i+1])
                    {   
                        sieve[i] = sieve[i+1]+1;
                        b=true;
                    }
                }
            }
        }
/*
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<sieve[i]<<" ";
        cout<<endl;
*/
        for(int i=0;i<n;i++)
            count += sieve[i];
        
        printf("%d\n",count);
    }
    return 0;
}

